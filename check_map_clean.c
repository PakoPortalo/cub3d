/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:18:04 by fportalo          #+#    #+#             */
/*   Updated: 2020/12/15 12:35:13 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_coordinates(int *x, int *y, mapstr *raw)
{
	if (!*x && !*y)
	{
		*x = raw->x;
		*y = raw->y;
	}
}

void	check_origin_errors(int i, int x, int y, mapstr *raw)
{
	if (i == 0)
	{

		perror("Error\nThere is no player. Map need an origin point (N, S, W, E)\n");
		exit (6);
	}
	if (i > 1)
	{
		perror("Error\nThere is more than one player. Map need just one origin point \n");
		exit (-1);
	}
	raw->x = x;
	raw->y = y;
}

void	find_origin(mapstr *raw)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;

	while (raw->x < ((int)ft_strlen(raw->map[raw->y]) - 1) && raw->y < (raw->rows - 1))
	{
		while (raw->map[raw->y][raw->x])
		{
			if ((ft_strchr("NSWE", raw->map[raw->y][raw->x])))
			{
				get_coordinates(&x, &y, raw);
				i++;
			}
			raw->x++;
		}
		raw->y++;
		raw->x = 0;
	}

	check_origin_errors(i, x, y, raw);
}

void		check_border(mapstr *raw, int y, int x)
{
	int i = 0;

	if (y == 0 || y == (raw->rows - 1) || x == 0  || x == ((int)ft_strlen(raw->map[y]) - 1))
	{

	while (raw->rows != 0)
	{
		printf("%s\n", raw->map[i]);
		i++;
		raw->rows--;
	}

		perror("Error\nYou need to introduce a correct map\n");
		exit (6);
	}
}

void		flood_fill(mapstr *raw, int y, int x)
{
	check_border(raw, y, x);
	if (ft_strchr("NSWE0 ", raw->map[y][x]))
		raw->map[y][x] = '3';

	if(raw->map[y - 1][x] == '0' || raw->map[y - 1][x] == ' ')
		flood_fill(raw, y - 1, x);
	if(raw->map[y][x + 1] == '0' || raw->map[y][x + 1] == ' ')
		flood_fill(raw, y, x + 1);
	if(raw->map[y + 1][x] == '0' || raw->map[y + 1][x] == ' ')
		flood_fill(raw, y + 1, x);
	if(raw->map[y][x - 1] == '0' || raw->map[y][x - 1] == ' ')
		flood_fill(raw, y, x - 1);
	if(raw->map[y + 1][x + 1] == '0' || raw->map[y + 1][x + 1] == ' ')
		flood_fill(raw, y + 1, x + 1);
	if(raw->map[y - 1][x + 1] == '0' || raw->map[y - 1][x + 1] == ' ')
		flood_fill(raw, y - 1, x + 1);
	if(raw->map[y - 1][x - 1] == '0' || raw->map[y - 1][x - 1] == ' ')
		flood_fill(raw, y - 1, x - 1);
	if(raw->map[y + 1][x - 1] == '0' || raw->map[y + 1][x - 1] == ' ')
		flood_fill(raw, y + 1, x - 1);

	if (raw->map[y][x] == '\0')
	{
		perror("Error\nYou need to introduce a correct map");
		exit (6);
	}
}

void		check_map(mapstr *raw, mapclean *map)
{
	inimap(map);

	if (raw->map[0][0] == '0' || raw->map[0][0] == '2' || \
		raw->map[0][ft_strlen(raw->map[0]) -1] == '0' || raw->map[0][ft_strlen(raw->map[0]) -1] == '2' || \
		raw->map[raw->rows - 1][ft_strlen(raw->map[raw->rows - 1]) - 1] == '0' || raw->map[raw->rows - 1][ft_strlen(raw->map[raw->rows - 1]) - 1] == '2' || \
		raw->map[raw->rows - 1][0] == '0' || raw->map[raw->rows - 1][0] == '2')

	{
		perror("Error\nYou need to introduce a correct map");
		exit (6);
	}


	find_origin(raw);
	flood_fill(raw, raw->y , raw->x);
}
