/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_struct_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 09:11:59 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/18 16:36:20 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	iniraw(mapstr *raw)
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
	raw->sprite_count = 0;
}

void	inimap(mapclean *map)
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
	map->orientation = '0';
	map->sprite_count = 0;
	map->rows = 0;
	map->savecheck = 0;
}

void	ininum(mapconfig *num)
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

void	inisprite(t_sprite *s)
{
	s->x = 0;
	s->y = 0;
	s->inv_det = 0;
	s->transform_x = 0;
	s->transform_y = 0;
	s->screen_x = 0;
	s->screen_y = 0;
	s->height = 0;
	s->width = 0;
	s->draw_start_x = 0;
	s->draw_end_x = 0;
	s->draw_start_y = 0;
	s->draw_end_y = 0;
	s->tex_x = 0;
	s->tex_y = 0;
}

void	inihandlekeys(t_handlekeys *keys)
{
	keys->left = 0;
	keys->up = 0;
	keys->right = 0;
	keys->down = 0;
	keys->rotLeft = 0;
	keys->rotRight = 0;
}
