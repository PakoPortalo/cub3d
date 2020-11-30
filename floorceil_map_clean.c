/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorceil_map_clean.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 08:47:56 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/30 09:45:45 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_number_variables(char **rgb, int i)
{
	if (rgb[i])
	{
		printf("Error. Number of floor/ceil arguments wrong\n");
		return (-1);
	}
	return (1);
}



int		get_floor_clean(mapstr *raw, mapclean *map)
{
	char **temp;

	temp = ft_split(raw->floor, ',');
	if (check_number_variables(temp, 3) == -1)
		return (-1);
	map->floor[0] = ft_atoi(temp[0]);
	map->floor[1] = ft_atoi(temp[1]);
	map->floor[2] = ft_atoi(temp[2]);
	free(temp);
	return (1);
}

int		get_ceil_clean(mapstr *raw, mapclean *map)
{
	char **temp;

	temp = ft_split(raw->ceil, ',');
	if (check_number_variables(temp, 3) == -1)
		return (-1);
	map->ceil[0] = ft_atoi(temp[0]);
	map->ceil[1] = ft_atoi(temp[1]);
	map->ceil[2] = ft_atoi(temp[2]);
	free(temp);
	return (1);
}

int		check_floor_ceil(mapstr *raw, mapclean *map)
{
	char **temp;

	temp = ft_split(raw->floor, ' ');
	if (check_number_variables(temp, 2) == -1)
		return (-1);
	raw->floor = temp[1];
	free(temp);
	get_floor_clean(raw, map);
	temp = ft_split(raw->ceil, ' ');
	if (check_number_variables(temp, 2) == -1)
		return (-1);
	raw->ceil = temp[1];
	free(temp);
	get_ceil_clean(raw, map);
	return (1);
}
