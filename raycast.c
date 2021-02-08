/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:33:18 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/08 10:34:44 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
		if(rc->map.map[(int)(rc->posY)][(int)(rc->posX + moveX)] != '1')
			rc->posX += moveX;
		if(rc->map.map[(int)(rc->posY + moveY)][(int)(rc->posX)] != '1')
			rc->posY += moveY;
	}
	if(rc->keys.down == 1)
	{
		if(rc->map.map[(int)(rc->posY)][(int)(rc->posX - moveX)] != '1')
			rc->posX -= moveX;
		if(rc->map.map[(int)(rc->posY - moveY)][(int)(rc->posX)] != '1')
			rc->posY -= moveY;
	}
	if(rc->keys.right == 1)
	{
		if(rc->map.map[(int)(rc->posY)][(int)(rc->posX - moveY)] != '1')
			rc->posX -= moveY;
		if(rc->map.map[(int)(rc->posY + moveX)][(int)(rc->posX)] != '1')
			rc->posY += moveX;
	}
	if(rc->keys.left == 1)
	{
		if(rc->map.map[(int)(rc->posY)][(int)(rc->posX + moveY)] != '1')
			rc->posX += moveY;
		if(rc->map.map[(int)(rc->posY - moveX)][(int)(rc->posX)] != '1')
			rc->posY -= moveX;
	}
	return (1);
}

int		rotate_player(t_raycast *rc)
{
	if(rc->keys.rotLeft == 1)
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
	if(rc->keys.rotRight == 1)
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
		if(rc->map.map[rc->mapY][rc->mapX] == '1' || rc->map.map[rc->mapY][rc->mapX] == '2')
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

	rc->drawStart = -(rc->lineHeight) / 2 + rc->map.h / 2;
	if(rc->drawStart < 0)
		rc->drawStart = 0;

	rc->drawEnd = rc->lineHeight / 2 + rc->map.h / 2;
	if(rc->drawEnd >= rc->map.h)
		rc->drawEnd = rc->map.h - 1;
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
		rc->mapX = rc->posX;
		rc->mapY = rc->posY;
		ft_raydir(rc, x);
		ft_deltadist(rc);
		ft_sidedist(rc);
		ft_rayhit(rc);
		ft_walldist(rc);
		
		// // Dibuja muros con la información de draw start y draw end
 		verLine(rc, x);
		x++;
	}
	player_movement(rc);
	mlx_put_image_to_window(rc->img.ptr, rc->img.win, rc->img.img, 0, 0);
	mlx_destroy_image(rc->img.ptr, rc->img.img);
	return(0);
}
