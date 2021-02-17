/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:18:04 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/17 19:16:29 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_origin_errors(int i, int x, int y, mapstr *raw)
{
	if (i == 0)
	{
		perror("Error\nMap need an Origin Point (N, S, W, E)\n");
		exit(6);
	}
	if (i > 1)
	{
		perror("Error\nThere is more than one Origin Point \n");
		exit(-1);
	}
	raw->x = x;
	raw->y = y;
}

void		find_origin(mapstr *raw, mapclean *map)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (raw->x < ((int)ft_strlen(raw->map[raw->y]) - 1) && \
	raw->y < (raw->rows - 1))
	{
		while (raw->map[raw->y][raw->x])
		{
			if ((ft_strchr("NSWE", raw->map[raw->y][raw->x])))
			{
				map->orientation = raw->map[raw->y][raw->x];
				get_coordinates(&x, &y, raw, map);
				i++;
			}
			raw->x++;
		}
		raw->y++;
		raw->x = 0;
	}
	check_origin_errors(i, x, y, raw);
}

void		flood_fill(mapstr *raw, int y, int x)
{
	check_border(raw, y, x);
	if (raw->map[y][x] == '2')
		raw->sprite_count++;
	if (ft_strchr("NSWE0 ", raw->map[y][x]))
		raw->map[y][x] = '3';
	if (raw->map[y][x] == '2')
		raw->map[y][x] = '4';
	flood_fill_sub(raw, y, x);
	if (raw->map[y][x] == '\0')
	{
		perror("Error\nYou need to introduce a correct map");
		exit(6);
	}
}

void		flood_fill_sub(mapstr *raw, int y, int x)
{
	if (raw->map[y - 1][x] != '1' && raw->map[y - 1][x] != '3' \
	&& raw->map[y - 1][x] != '4')
		flood_fill(raw, y - 1, x);
	if (raw->map[y][x + 1] != '1' && raw->map[y][x + 1] != '3' \
	&& raw->map[y][x + 1] != '4')
		flood_fill(raw, y, x + 1);
	if (raw->map[y + 1][x] != '1' && raw->map[y + 1][x] != '3' \
	&& raw->map[y + 1][x] != '4')
		flood_fill(raw, y + 1, x);
	if (raw->map[y][x - 1] != '1' && raw->map[y][x - 1] != '3' \
	&& raw->map[y][x - 1] != '4')
		flood_fill(raw, y, x - 1);
	if (raw->map[y + 1][x + 1] != '1' && raw->map[y + 1][x + 1] != '3' \
	&& raw->map[y + 1][x + 1] != '4')
		flood_fill(raw, y + 1, x + 1);
	if (raw->map[y - 1][x + 1] != '1' && raw->map[y - 1][x + 1] != '3' \
	&& raw->map[y - 1][x + 1] != '4')
		flood_fill(raw, y - 1, x + 1);
	if (raw->map[y - 1][x - 1] != '1' && raw->map[y - 1][x - 1] != '3' \
	&& raw->map[y - 1][x - 1] != '4')
		flood_fill(raw, y - 1, x - 1);
	if (raw->map[y + 1][x - 1] != '1' && raw->map[y + 1][x - 1] != '3' \
	&& raw->map[y + 1][x - 1] != '4')
		flood_fill(raw, y + 1, x - 1);
}

void		check_map(mapstr *raw, mapclean *map)
{
	if (raw->map[0][0] == '0' || raw->map[0][0] == '2' || \
	raw->map[0][ft_strlen(raw->map[0]) - 1] == '0' || \
	raw->map[0][ft_strlen(raw->map[0]) - 1] == '2' || \
	raw->map[raw->rows - 1][ft_strlen(raw->map[raw->rows - 1]) - 1] == '0' || \
	raw->map[raw->rows - 1][ft_strlen(raw->map[raw->rows - 1]) - 1] == '2' || \
	raw->map[raw->rows - 1][0] == '0' || raw->map[raw->rows - 1][0] == '2')
	{
		perror("Error\nYou need to introduce a correct map");
		exit(6);
	}
	find_origin(raw, map);
	flood_fill(raw, raw->y, raw->x);
	map->sprite_count = raw->sprite_count;
}
