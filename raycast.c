/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:33:18 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/17 18:54:50 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player_updown(t_raycast *rc, double move_x, double move_y)
{
	if (rc->keys.up == 1)
	{
		if (rc->map.map[(int)(rc->posX + move_x)][(int)(rc->posY)] == '3')
			rc->posX += move_x;
		if (rc->map.map[(int)(rc->posX)][(int)(rc->posY + move_y)] == '3')
			rc->posY += move_y;
	}
	if (rc->keys.down == 1)
	{
		if (rc->map.map[(int)(rc->posX - move_x)][(int)(rc->posY)] == '3')
			rc->posX -= move_x;
		if (rc->map.map[(int)(rc->posX)][(int)(rc->posY - move_y)] == '3')
			rc->posY -= move_y;
	}
}

void	move_player_leftright(t_raycast *rc, double move_x, double move_y)
{
	if (rc->keys.left == 1)
	{
		if (rc->map.map[(int)(rc->posX)][(int)(rc->posY + move_x)] == '3')
			rc->posY += move_x;
		if (rc->map.map[(int)(rc->posX - move_y)][(int)(rc->posY)] == '3')
			rc->posX -= move_y;
	}
	if (rc->keys.right == 1)
	{
		if (rc->map.map[(int)(rc->posX)][(int)(rc->posY - move_x)] == '3')
			rc->posY -= move_x;
		if (rc->map.map[(int)(rc->posX + move_y)][(int)(rc->posY)] == '3')
			rc->posX += move_y;
	}
}

void	rotate_player(t_raycast *rc)
{
	rc->oldDirX = rc->dirX;
	if (rc->keys.rotRight == 1)
	{
		rc->dirX = rc->dirX * cos(-rc->rotSpeed) \
		- rc->dirY * sin(-rc->rotSpeed);
		rc->dirY = rc->oldDirX * sin(-rc->rotSpeed) \
		+ rc->dirY * cos(-rc->rotSpeed);
		rc->oldPlaneX = rc->planeX;
		rc->planeX = rc->planeX * cos(-rc->rotSpeed) \
		- rc->planeY * sin(-rc->rotSpeed);
		rc->planeY = rc->oldPlaneX * sin(-rc->rotSpeed) \
		+ rc->planeY * cos(-rc->rotSpeed);
	}
	if (rc->keys.rotLeft == 1)
	{
		rc->dirX = rc->dirX * cos(rc->rotSpeed) \
		- rc->dirY * sin(rc->rotSpeed);
		rc->dirY = rc->oldDirX * sin(rc->rotSpeed) \
		+ rc->dirY * cos(rc->rotSpeed);
		rc->oldPlaneX = rc->planeX;
		rc->planeX = rc->planeX * cos(rc->rotSpeed) \
		- rc->planeY * sin(rc->rotSpeed);
		rc->planeY = rc->oldPlaneX * sin(rc->rotSpeed) \
		+ rc->planeY * cos(rc->rotSpeed);
	}
}

void	player_movement(t_raycast *rc)
{
	double move_x;
	double move_y;

	move_x = rc->dirX * rc->moveSpeed;
	move_y = rc->dirY * rc->moveSpeed;
	move_player_updown(rc, move_x, move_y);
	move_player_leftright(rc, move_x, move_y);
	rotate_player(rc);
}

int		raycast_maths(t_raycast *rc)
{
	int x;

	x = 0;
	rc->img.img = mlx_new_image(rc->img.ptr, rc->map.w, rc->map.h);
	rc->img.addr = mlx_get_data_addr(rc->img.img, &rc->img.bits_per_pixel, \
	&rc->img.line_length, &rc->img.endian);
	while (x < rc->map.w)
	{
		rc->mapX = (int)rc->posX;
		rc->mapY = (int)rc->posY;
		ft_raydir(rc, x);
		ft_deltadist(rc);
		ft_sidedist(rc);
		ft_rayhit(rc);
		ft_walldist(rc);
		rc->zBuffer[x] = rc->perpWallDist;
		ft_buffer(rc, x);
		x++;
	}
	if (rc->map.sprite_count)
		ft_sprites(rc);
	mlx_put_image_to_window(rc->img.ptr, rc->img.win, rc->img.img, 0, 0);
	mlx_destroy_image(rc->img.ptr, rc->img.img);
	player_movement(rc);
	return (1);
}
