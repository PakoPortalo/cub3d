/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:31:12 by fportalo          #+#    #+#             */
/*   Updated: 2021/01/25 11:50:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		raycast_start(t_raycast *rc)
{
	rc->posX = (double)rc->map.x + 0.5f;
	rc->posY = (double)rc->map.y + 0.5f;

	if (rc->map.orientation == 'N')
	{
		rc->planeX = 0.66;
		rc->planeY = 0;
		rc->dirX = 0;
		rc->dirY = -1;
	}
	if (rc->map.orientation == 'S')
	{
		rc->planeX = -0.66;
		rc->planeY = 0;
		rc->dirX = 0;
		rc->dirY = 1;
	}
		if (rc->map.orientation == 'E')
	{
		rc->planeX = 0;
		rc->planeY = 0.66;
		rc->dirX = 1;
		rc->dirY = 0;
	}
	if (rc->map.orientation == 'W')
	{
		rc->planeX = 0;
		rc->planeY = -0.66;
		rc->dirX = -1;
		rc->dirY = 0;
	}
	return(1);
}

int			printer_cub3d(mapclean *map)
{
	t_data	img;
	t_raycast rc;
	t_handlekeys keys;

	img.ptr = mlx_init();
	img.win = mlx_new_window(img.ptr, map->w, map->h, "Hello world!");

	rc.map = *map;
	rc.img = img;

	inihandlekeys(&keys);
	rc.keys = keys;
	iniraycast(&rc);
	raycast_start(&rc);
	mlx_hook(rc.img.win, 2, 1L << 0, funky_func_keypress, &rc);
	mlx_hook(rc.img.win, 3, 1L << 1, funky_func_keyrelease, &rc);
	mlx_hook(rc.img.win, 17, 1L<<17, exit_win, &rc.img);
	mlx_loop_hook(img.ptr, raycast_maths, &rc);
	mlx_loop(img.ptr);
	return (0);
}
