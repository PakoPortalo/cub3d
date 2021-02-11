/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:33:18 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/11 16:16:42 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int			get_pixel(t_data *frame, int x, int y)
{
	char	*dst;

	dst = frame->addr + (y * frame->line_length + x * (frame->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

int			rgb_to_hex(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		verLine(t_raycast *rc, int x)
{
	int		y;

	y = 0;
	while (y < rc->map.h)
	{
		if(y <= rc->drawStart)
			my_mlx_pixel_put(&rc->img, x, y, 0x7effdb); // techo amarillo
		else if (y > rc->drawStart && y < rc->drawEnd)
		{
			if (rc->side == 0)
				my_mlx_pixel_put(&rc->img, x, y, 0xb693fe); // muro verde
			else if (rc->side == 1)
				my_mlx_pixel_put(&rc->img, x, y, 0x8c82fc); // muro verde oscuro
		}
		else if (y >= rc->drawEnd)
			my_mlx_pixel_put(&rc->img, x, y, 0xff9de2 ); // suelo marron

		y++;
	}
	return (0);
}

int		move_player(t_raycast *rc, double moveX, double moveY)
{
	if(rc->keys.up == 1)
	{
		if(rc->map.map[(int)(rc->posX + moveX)][(int)(rc->posY)] != '1')
			rc->posX += moveX;
		if(rc->map.map[(int)(rc->posX)][(int)(rc->posY + moveY)] != '1')
			rc->posY += moveY;
	}
	if(rc->keys.down == 1)
	{
		if(rc->map.map[(int)(rc->posX - moveX)][(int)(rc->posY)] != '1')
			rc->posX -= moveX;
		if(rc->map.map[(int)(rc->posX)][(int)(rc->posY - moveY)] != '1')
			rc->posY -= moveY;
	}
	if(rc->keys.left == 1)
	{
		if(rc->map.map[(int)(rc->posX)][(int)(rc->posY + moveX)] != '1')
			rc->posY += moveX;
		if(rc->map.map[(int)(rc->posX - moveY)][(int)(rc->posY)] != '1')
			rc->posX -= moveY;
	}
	if(rc->keys.right == 1)
	{
		if(rc->map.map[(int)(rc->posX)][(int)(rc->posY - moveX)] != '1')
			rc->posY -= moveX;
		if(rc->map.map[(int)(rc->posX + moveY)][(int)(rc->posY)] != '1')
			rc->posX += moveY;
	}
	return (1);
}

int		rotate_player(t_raycast *rc)
{
	if(rc->keys.rotRight == 1)
	{
		//both camera direction and camera plane must be rotated
		rc->oldDirX = rc->dirX;
		rc->dirX = rc->dirX * cos(-rc->rotSpeed) - rc->dirY * sin(-rc->rotSpeed);
		rc->dirY = rc->oldDirX * sin(-rc->rotSpeed) + rc->dirY * cos(-rc->rotSpeed);

		rc->oldPlaneX = rc->planeX;
		rc->planeX = rc->planeX * cos(-rc->rotSpeed) - rc->planeY * sin(-rc->rotSpeed);
		rc->planeY = rc->oldPlaneX * sin(-rc->rotSpeed) + rc->planeY * cos(-rc->rotSpeed);
	}
	//rotate to the left
	if(rc->keys.rotLeft == 1)
	{
		//both camera direction and camera plane must be rotated
		rc->oldDirX = rc->dirX;
		rc->dirX = rc->dirX * cos(rc->rotSpeed) - rc->dirY * sin(rc->rotSpeed);
		rc->dirY = rc->oldDirX * sin(rc->rotSpeed) + rc->dirY * cos(rc->rotSpeed);
		rc->oldPlaneX = rc->planeX;
		rc->planeX = rc->planeX * cos(rc->rotSpeed) - rc->planeY * sin(rc->rotSpeed);
		rc->planeY = rc->oldPlaneX * sin(rc->rotSpeed) + rc->planeY * cos(rc->rotSpeed);
	}
	return(1);
}

int		player_movement(t_raycast *rc)
{
	double moveX;
	double moveY;

	moveX = rc->dirX * rc->moveSpeed;
	moveY = rc->dirY * rc->moveSpeed;
	move_player(rc, moveX, moveY);
	rotate_player(rc);
	return(1);
}

void	ft_raydir(t_raycast *rc, int x)
{
		rc->cameraX = 2 * x / (double)rc->map.w - 1;
		rc->rayDirX = rc->dirX + rc->planeX * rc->cameraX;
		rc->rayDirY = rc->dirY + rc->planeY * rc->cameraX;
}

void	ft_deltadist(t_raycast *rc)
{
	if (rc->rayDirX == 0)
	{
		rc->deltaDistX = 1;
		rc->deltaDistY = 0;
	}
	else if (rc->rayDirY == 0)
	{
		rc->deltaDistX = 0;
		rc->deltaDistY = 1;
	}
	else
	{
		rc->deltaDistX = fabs(1 / rc->rayDirX);
		rc->deltaDistY = fabs(1 / rc->rayDirY);
	}
	// rc->deltaDistX = sqrt(1 + (rc->rayDirY * rc->rayDirY) / (rc->rayDirX * rc->rayDirX));
	// rc->deltaDistY = sqrt(1 + (rc->rayDirX * rc->rayDirX) / (rc->rayDirY * rc->rayDirY));
}

void	ft_sidedist(t_raycast *rc)
{
	rc->hit = 0;
	if (rc->rayDirX < 0)
	{
		rc->stepX = -1;
		rc->sideDistX = (rc->posX - rc->mapX) * rc->deltaDistX;
	}
	else
	{
		rc->stepX = 1;
		rc->sideDistX = (rc->mapX + 1.0 - rc->posX) * rc->deltaDistX;
	}
	if(rc->rayDirY < 0)
	{
		rc->stepY = -1;
		rc->sideDistY = (rc->posY - rc->mapY) * rc->deltaDistY;
	}
	else
	{
		rc->stepY = 1;
		rc->sideDistY = (rc->mapY + 1.0 - rc->posY) * rc->deltaDistY;
	}
}

void	ft_rayhit(t_raycast *rc)
{
	while (rc->hit == 0)
	{
		if(rc->sideDistX < rc->sideDistY)
		{
			rc->sideDistX += rc->deltaDistX;
			rc->mapX += rc->stepX;
			rc->side = 0;
		}
		else
		{
			rc->sideDistY += rc->deltaDistY;
			rc->mapY += rc->stepY;
			rc->side = 1;
		}
		if(rc->map.map[rc->mapX][rc->mapY] == '1')
			rc->hit = 1;
	}
}

void	ft_walldist(t_raycast *rc)
{
	if(rc->side == 0)
		rc->perpWallDist = (rc->mapX - rc->posX + (1 - rc->stepX) / 2) / rc->rayDirX;
	else
		rc->perpWallDist = (rc->mapY - rc->posY + (1 - rc->stepY) / 2) / rc->rayDirY;
	rc->lineHeight = (int)(rc->map.h / rc->perpWallDist);

	// rc->drawStart = -(rc->lineHeight) / 2 + rc->map.h / 2;
	// if(rc->drawStart < 0)
	// 	rc->drawStart = 0;

	// rc->drawEnd = rc->lineHeight / 2 + rc->map.h / 2;
	// if(rc->drawEnd >= rc->map.h)
	// 	rc->drawEnd = rc->map.h - 1;
}

void	buffer_line(t_raycast *rc, t_tex_img *tex, int x, int line_height)
{
	int	i;
	double	step;
	double	tex_pos;

	i = 0;
	step = 1.0 *  tex->height / line_height;
	tex_pos = (rc->drawStart - rc->map.h / 2 + line_height / 2) * step;
	while (i < rc->map.h)
	{
		if (i < rc->drawStart)
			my_mlx_pixel_put(&rc->img, x, i, rgb_to_hex(0, rc->map.ceil[0], rc->map.ceil[1], rc->map.ceil[2]));
		else if ( i >= rc->drawEnd)
			my_mlx_pixel_put(&rc->img, x, i, rgb_to_hex(0, rc->map.floor[0], rc->map.floor[1], rc->map.floor[2]));
		else if ( i > rc->drawStart && i  < rc->drawEnd)
		{
			if ((rc->texY = (int)tex_pos) < 0)
				rc->texY = 0;
			tex_pos += step;
			my_mlx_pixel_put(&rc->img, x, i, get_pixel(&tex->img, rc->texX, rc->texY));
		}
		i++;
	}
}

void	ft_buffer(t_raycast *rc, int x)
{
	int			line_height;
	t_tex_img	*texture;

	texture = NULL;
	line_height = (int)(rc->map.h / rc->perpWallDist);
	rc->drawStart = -line_height / 2  + rc->map.h / 2;
	if(rc->drawStart < 0)
		rc->drawStart = 0;
		
	rc->drawEnd = line_height / 2 + rc->map.h / 2;
	if (rc->drawEnd >= rc->map.h)
		rc->drawEnd = rc->map.h - 1;

	//getting texture
	if(rc->side == 0) 
	{
		if (rc->stepX < 0)
			texture = &rc->tex.textures[0];
		else
			texture = &rc->tex.textures[1];
	}
	else
	{
		if (rc->stepY > 0)
			texture = &rc->tex.textures[2];
		else
			texture = &rc->tex.textures[3];
	}


	//cord X texture
	if (rc->side == 0)
		rc->wallX = rc->posY + rc->perpWallDist * rc->rayDirY;
	else
		rc->wallX = rc->posX + rc->perpWallDist * rc->rayDirX;
	rc->wallX -= floor(rc->wallX);
	rc->texX = texture->width - (int)(rc->wallX * (double)texture->width) - 1;

	if (rc->side == 0 && rc->rayDirX > 0)
		rc->texX = texture->width - rc->texX - 1;
	if (rc->side == 1 && rc->rayDirY < 0)
		rc->texX = texture->width - rc->texX - 1;

	//paint lines
	buffer_line(rc, texture, x, line_height);


}

int		raycast_maths(t_raycast *rc)
{
	int x;

	x = 0;
	rc->img.img = mlx_new_image(rc->img.ptr, rc->map.w, rc->map.h);
	rc->img.addr = mlx_get_data_addr(rc->img.img, &rc->img.bits_per_pixel, &rc->img.line_length,
								&rc->img.endian);
	while(x < rc->map.w)
	{
		rc->mapX = (int)rc->posX;
		rc->mapY = (int)rc->posY;
		ft_raydir(rc, x);
		ft_deltadist(rc);
		ft_sidedist(rc);
		ft_rayhit(rc);
		ft_walldist(rc);
		ft_buffer(rc, x);
	// rc->lineHeight = (int)(rc->map.h / rc->perpWallDist);
	// rc->drawStart = -rc->lineHeight / 2  + rc->map.h / 2;
	// if(rc->drawStart < 0)
	// 	rc->drawStart = 0;
		
	// rc->drawEnd = rc->lineHeight / 2 + rc->map.h / 2;
	// if (rc->drawEnd >= rc->map.h)
	// 	rc->drawEnd = rc->map.h - 1;
	// 	// // Dibuja muros con la información de draw start y draw end
 	// 	verLine(rc, x);
		x++;
	}
	mlx_put_image_to_window(rc->img.ptr, rc->img.win, rc->img.img, 0, 0);
	mlx_destroy_image(rc->img.ptr, rc->img.img);
	player_movement(rc);
	return(0);
}
