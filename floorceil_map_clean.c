/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorceil_map_clean.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 08:47:56 by fportalo          #+#    #+#             */
/*   Updated: 2020/12/10 13:25:25 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_number_variables(char **rgb, int i)
{
	if (rgb[i])
	{
		perror("Error\nNumber of floor/ceil arguments wrong\n");
		exit (5);
	}
}



// void		get_floor_clean(mapstr *raw, mapclean *map)
// {
// 	char **temp;

// 	temp = ft_split(raw->floor, ',');
// 	check_number_variables(temp, 3);
// 	map->floor[0] = ft_atoi(temp[0]);
// 	map->floor[1] = ft_atoi(temp[1]);
// 	map->floor[2] = ft_atoi(temp[2]);
// 	free(temp);
// }

// void		get_ceil_clean(mapstr *raw, mapclean *map)
// {
// 	char **temp;

// 	temp = ft_split(raw->ceil, ',');
// 	check_number_variables(temp, 3);
// 	map->ceil[0] = ft_atoi(temp[0]);
// 	map->ceil[1] = ft_atoi(temp[1]);
// 	map->ceil[2] = ft_atoi(temp[2]);
// 	free(temp);
// }

// void		check_floor_ceil(mapstr *raw, mapclean *map)
// {
// 	char **temp;

// 	temp = ft_split(raw->floor, ' ');
// 	check_number_variables(temp, 2);
// 	raw->floor = temp[1];
// 	free(temp);
// 	get_floor_clean(raw, map);
// 	temp = ft_split(raw->ceil, ' ');
// 	check_number_variables(temp, 2);
// 	raw->ceil = temp[1];
// 	free(temp);
// 	get_ceil_clean(raw, map);
// }

void		comma_counter(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
	{
		perror("Error\nNumber of floor/ceil arguments wrong\n");
		exit (5);
	}
}

void		check_number(char **args, int *rgb)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(args[j])
	{
		i = 0;
		while(args[j][i])
		{
			if (!ft_isdigit(args[j][i]))
			{
				perror("Error\nFloor/Ceil doesn't have valid numbers.\n");
				exit (3);
			}
			i++;
		}
		j++;
	}
	rgb[0] = ft_atoi(args[0]);
	rgb[1] = ft_atoi(args[1]);
	rgb[2] = ft_atoi(args[2]);
	//checkarg[1], args[1], args[2]
	if ( !(rgb[0] >= 0 && rgb[0] <= 255) || !(rgb[1] >= 0 && rgb[1] <= 255) || \
	!(rgb[1] >= 0 && rgb[1] <= 255))
	{
		perror("Error\nFloor and Ceil parametrers must be between 0 and 255\n");
		exit (5);
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
	argsceil[0] = ft_strtrim(checkargceil[1], " ");
	argsceil[1] = ft_strtrim(argsceil[1], " ");
	argsceil[2] = ft_strtrim(argsceil[2], " ");
	check_number(argsceil, map->ceil);
	map->floor[0] = ft_atoi(checkargceil[1]);
	map->floor[1] = ft_atoi(argsceil[1]);
	map->floor[2] = ft_atoi(argsceil[2]);
}
void		check_floor(mapstr *raw, mapclean *map)
{
	char	**argsfloor;
	char	**checkargfloor;

	//First Floor Argument
	argsfloor = ft_split(raw->floor, ',');
	check_number_variables(argsfloor, 3);
	checkargfloor = ft_split(argsfloor[0], ' ');
	check_number_variables(checkargfloor, 2);
	argsfloor[0] = ft_strtrim(checkargfloor[1], " ");
	argsfloor[1] = ft_strtrim(argsfloor[1], " ");
	argsfloor[2] = ft_strtrim(argsfloor[2], " ");
	check_number(argsfloor, map->floor);
	map->floor[0] = ft_atoi(checkargfloor[1]);
	map->floor[1] = ft_atoi(argsfloor[1]);
	map->floor[2] = ft_atoi(argsfloor[2]);
}

void		check_floor_ceil(mapstr *raw, mapclean *map)
{
	comma_counter(raw->floor);
	comma_counter(raw->ceil);
	check_floor(raw, map);
	check_ceil(raw, map);

}