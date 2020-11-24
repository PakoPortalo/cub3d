/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 09:11:59 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/24 11:18:02 by fportalo         ###   ########.fr       */
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
	raw->err = 0;
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
	map->floor = 0;
	map->ceil = 0;
	map->map = NULL;
}

