/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 09:11:59 by fportalo          #+#    #+#             */
/*   Updated: 2021/01/07 12:51:20 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		iniraw(mapstr *raw)
{
	raw->res = NULL;
	raw->north = NULL;
	raw->south = NULL;
	raw->west = NULL;
	raw->east = NULL;
	raw->sprite = NULL;
	raw->floor = NULL;
	raw->ceil = NULL;
	raw->map = NULL;
	raw->rows = 0;
	raw->varnum = 0;
	raw->x = 0;
	raw->y = 0;
}

void		inimap(mapclean *map)
{
	map->w = 0;
	map->h = 0;
	map->north = NULL;
	map->south = NULL;
	map->west = NULL;
	map->east = NULL;
	map->sprite = NULL;
	map->floor[0] = -1;
	map->floor[1] = -1;
	map->floor[2] = -1;
	map->ceil[0] = -1;
	map->ceil[1] = -1;
	map->ceil[2] = -1;
	map->map = NULL;
	map->x = 0;
	map->y = 0;
}

void		ininum(mapconfig *num)
{
	num->res = 0;
	num->north = 0;
	num->south = 0;
	num->west = 0;
	num->east = 0;
	num->sprite = 0;
	num->floor = 0;
	num->ceil = 0;
}

void		iniraycast(t_raycast *rc, t_data *img)
{
	rc->posX = 0;
	rc->posY = 0;
	rc->dirX = -1;
	rc->dirY = 0;
	rc->planeX = 0;
	rc->planeY = 0.66;
	rc->cameraX = 0;
	rc->rayDirX = 0;
	rc->rayDirY = 0;
	rc->mapX = 0;
	rc->mapY = 0;
	rc->sideDistX = 0;
	rc->sideDistY = 0;
	rc->deltaDistX = 0;
	rc->deltaDistY = 0;
	rc->perpWallDist = 0;
	rc->stepX = 0;
	rc->stepY = 0;
	rc->hit = 0;
	rc->side = 0;
	rc->lineHeight = 0;
	rc->drawStart = 0;
	rc->drawEnd = 0;
	// rc->frameTime = 0;
	// rc->moveSpeed = 0;
	// rc->rotSpeed = 0;
	rc->oldDirX = 0;
	rc->oldPlaneX = 0;
	img_to_rc(rc, img);
}

void	map_to_img(t_data *img, mapclean *map)
{
	img->map.w = map->w;
	img->map.h = map->h;
	img->map.north = map->north;
	img->map.south = map->south;
	img->map.west = map->west;
	img->map.east = map->east;
	img->map.sprite = map->sprite;
	img->map.floor[0] = map->floor[0];
	img->map.floor[1] = map->floor[1];
	img->map.floor[2] = map->floor[2];
	img->map.ceil[0] = map->ceil[0];
	img->map.ceil[1] = map->ceil[1];
	img->map.ceil[2] = map->ceil[2];
	img->map.map = map->map;
	img->map.x = map->x;
	img->map.y = map->y;
}

void	img_to_rc(t_raycast *rc, t_data *img)
{
	rc->img.ptr = img->ptr;
	rc->img.win = img->win;
	rc->img.img = img->img;
	rc->img.addr = img->addr;
	rc->img.bits_per_pixel = img->bits_per_pixel;
	rc->img.line_length = img->line_length;
	rc->img.line_height = img->line_height;
	rc->img.endian = img->endian;
	map_to_img(&rc->img, &img->map);
}