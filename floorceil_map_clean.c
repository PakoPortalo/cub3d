/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorceil_map_clean.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 08:47:56 by fportalo          #+#    #+#             */
/*   Updated: 2020/12/04 13:07:41 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_number_variables(char **rgb, int i)
{
	if (rgb[i])
	{
		perror("Error. Number of floor/ceil arguments wrong\n");
		exit (5);
	}
}



void		get_floor_clean(mapstr *raw, mapclean *map)
{
	char **temp;

	temp = ft_split(raw->floor, ',');
	check_number_variables(temp, 3);
	map->floor[0] = ft_atoi(temp[0]);
	map->floor[1] = ft_atoi(temp[1]);
	map->floor[2] = ft_atoi(temp[2]);
	free(temp);
}

void		get_ceil_clean(mapstr *raw, mapclean *map)
{
	char **temp;

	temp = ft_split(raw->ceil, ',');
	check_number_variables(temp, 3);
	map->ceil[0] = ft_atoi(temp[0]);
	map->ceil[1] = ft_atoi(temp[1]);
	map->ceil[2] = ft_atoi(temp[2]);
	free(temp);
}

void		check_floor_ceil(mapstr *raw, mapclean *map)
{
	char **temp;

	temp = ft_split(raw->floor, ' ');
	check_number_variables(temp, 2);
	raw->floor = temp[1];
	free(temp);
	get_floor_clean(raw, map);
	temp = ft_split(raw->ceil, ' ');
	check_number_variables(temp, 2);
	raw->ceil = temp[1];
	free(temp);
	get_ceil_clean(raw, map);
}
