/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorceil_map_clean.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 08:47:56 by fportalo          #+#    #+#             */
/*   Updated: 2020/12/21 10:44:00 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		alldigit(char **args)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (args[j])
	{
		i = 0;
		while (args[j][i])
		{
			if (!ft_isdigit(args[j][i]))
			{
				perror("Error\nFloor/Ceil doesn't have valid numbers.\n");
				exit(3);
			}
			i++;
		}
		j++;
	}
}

void		check_number(char **args, int *rgb)
{
	alldigit(args);
	rgb[0] = ft_atoi(args[0]);
	rgb[1] = ft_atoi(args[1]);
	rgb[2] = ft_atoi(args[2]);
	if (!(rgb[0] >= 0 && rgb[0] <= 255) || !(rgb[1] >= 0 && rgb[1] <= 255) || \
	!(rgb[1] >= 0 && rgb[1] <= 255) || !(rgb[2] >= 0 && rgb[2] <= 255))
	{
		perror("Error\nFloor and Ceil parametrers must be between 0 and 255\n");
		exit(5);
	}
}

void		check_ceil(mapstr *raw, mapclean *map)
{
	char	**argsceil;
	char	**checkargceil;

	argsceil = ft_split(raw->ceil, ',');
	check_number_variables(argsceil, 3);
	checkargceil = ft_split(argsceil[0], ' ');
	check_number_variables(checkargceil, 2);
	free(argsceil[0]);
	argsceil[0] = ft_strtrim(checkargceil[1], " ");
	check_number(argsceil, map->ceil);
	ft_freearray(checkargceil);
	ft_freearray(argsceil);
}

void		check_floor(mapstr *raw, mapclean *map)
{
	char	**argsfloor;
	char	**checkargfloor;

	argsfloor = ft_split(raw->floor, ',');
	check_number_variables(argsfloor, 3);
	checkargfloor = ft_split(argsfloor[0], ' ');
	check_number_variables(checkargfloor, 2);
	free(argsfloor[0]);
	argsfloor[0] = ft_strtrim(checkargfloor[1], " ");
	check_number(argsfloor, map->floor);
	ft_freearray(checkargfloor);
	ft_freearray(argsfloor);
}

void		check_floor_ceil(mapstr *raw, mapclean *map)
{
	comma_counter(raw->floor);
	comma_counter(raw->ceil);
	raw->floor = floor_ceil_spaces(raw->floor);
	raw->ceil = floor_ceil_spaces(raw->ceil);
	check_floor(raw, map);
	check_ceil(raw, map);
}
