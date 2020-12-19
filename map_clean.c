/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamagotchi <tamagotchi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:06:44 by fportalo          #+#    #+#             */
/*   Updated: 2020/12/19 18:24:17 by tamagotchi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_raw(mapstr *raw)
{

	free(raw->res);
	free(raw->north);
	free(raw->south);
	free(raw->west);
	free(raw->east);	
	free(raw->sprite);
	free(raw->floor);
	free(raw->ceil);
	ft_freearray(raw->map);
}

void		save_map_info(mapstr *raw, mapclean *map)
{
	inimap(map);
	check_resolution(raw, map);
	check_texture(raw, map);
	check_floor_ceil(raw, map);
	check_map(raw, map);
	map->map = raw->map;
	free_raw(raw);
}
