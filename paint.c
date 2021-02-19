/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:31:12 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/19 12:33:15 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	orientation_northsouth(t_raycast *rc)
{
	if (rc->map.orientation == 'N')
	{
		rc->dir_x = -1;
		rc->dir_y = 0;
		rc->plane_x = 0;
		rc->plane_y = 0.66;
	}
	if (rc->map.orientation == 'S')
	{
		rc->dir_x = 1;
		rc->dir_y = 0;
		rc->plane_x = 0;
		rc->plane_y = -0.66;
	}
}

void	orientation_eastwest(t_raycast *rc)
{
	if (rc->map.orientation == 'E')
	{
		rc->dir_x = 0;
		rc->dir_y = 1;
		rc->plane_x = 0.66;
		rc->plane_y = 0;
	}
	if (rc->map.orientation == 'W')
	{
		rc->dir_x = 0;
		rc->dir_y = -1;
		rc->plane_x = -0.66;
		rc->plane_y = 0;
	}
}

int		raycast_start(t_raycast *rc)
{
	rc->pos_x = (double)rc->map.y + 0.5f;
	rc->pos_y = (double)rc->map.x + 0.5f;
	load_all_textures(rc);
	rc->z_buffer = malloc(sizeof(double) * rc->map.w);
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

int		printer_cub3d(t_mapclean *map)
{
	t_data			img;
	t_raycast		rc;
	t_handlekeys	keys;

	img.ptr = mlx_init();
	mlx_get_screen_size(rc.img.ptr, &(map->max_w), &(map->max_h));
	if (map->max_w < map->w)
		map->w = map->max_w;
	if (map->max_h < map->h)
		map->h = map->max_h;
	img.win = mlx_new_window(img.ptr, map->w, map->h, "Pako Portalo's Cub3d");
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
