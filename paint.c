/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:31:12 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/17 19:35:05 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	orientation_northsouth(t_raycast *rc)
{
	if (rc->map.orientation == 'N')
	{
		rc->dirX = -1;
		rc->dirY = 0;
		rc->planeX = 0;
		rc->planeY = 0.66;
	}
	if (rc->map.orientation == 'S')
	{
		rc->dirX = 1;
		rc->dirY = 0;
		rc->planeX = 0;
		rc->planeY = -0.66;
	}
}

void	orientation_eastwest(t_raycast *rc)
{
	if (rc->map.orientation == 'E')
	{
		rc->dirX = 0;
		rc->dirY = 1;
		rc->planeX = 0.66;
		rc->planeY = 0;
	}
	if (rc->map.orientation == 'W')
	{
		rc->dirX = 0;
		rc->dirY = -1;
		rc->planeX = -0.66;
		rc->planeY = 0;
	}
}

int		raycast_start(t_raycast *rc)
{
	rc->posX = (double)rc->map.y + 0.5f;
	rc->posY = (double)rc->map.x + 0.5f;
	load_all_textures(rc);
	rc->zBuffer = malloc(sizeof(double) * rc->map.w);
	orientation_northsouth(rc);
	orientation_eastwest(rc);
	if (rc->map.sprite_count > 0)
	{
		rc->sprite = (t_sprite *)malloc(sizeof(t_sprite) * \
		rc->map.sprite_count);
		save_sprites(rc);
	}
	return (1);
}

int		printer_cub3d(mapclean *map)
{
	t_data			img;
	t_raycast		rc;
	t_handlekeys	keys;

	img.ptr = mlx_init();
	img.win = mlx_new_window(img.ptr, map->w, map->h, "Hello world!");
	rc.map = *map;
	rc.img = img;
	inihandlekeys(&keys);
	rc.keys = keys;
	iniraycast_1(&rc);
	iniraycast_2(&rc);
	raycast_start(&rc);
	mlx_hook(rc.img.win, 2, 1L << 0, funky_func_keypress, &rc);
	mlx_hook(rc.img.win, 3, 1L << 1, funky_func_keyrelease, &rc);
	mlx_hook(rc.img.win, 17, 1L << 17, exit_win, &rc.img);
	mlx_loop_hook(img.ptr, raycast_maths, &rc);
	mlx_loop(img.ptr);
	return (0);
}
