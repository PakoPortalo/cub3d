/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:18:04 by fportalo          #+#    #+#             */
/*   Updated: 2020/12/03 11:23:28 by fportalo         ###   ########.fr       */
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

int	check_origin_errors(int i, int x, int y, mapstr *raw)
{
	if (i == 0)
	{
		printf("Error. There is no player. Map need an origin point (N, S, W, E)\n");
		return (-1);
	}
	if (i > 1)
	{
		printf("Error. There is more than one player. Map need just one origin point \n");
		return (-1);
	}
	raw->x = x;
	raw->y = y;
	return(1);
}

int	find_origin(mapstr *raw)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (raw->x < (int)ft_strlen(raw->map[raw->y]) && raw->y < (raw->rows - 1))
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
	if (check_origin_errors(i, x, y, raw) == -1)
		return(-1);
	return (1);
}

int		check_border(mapstr *raw)
{
	int i;
	int j;

	i = 0;
	while (i < raw->rows) //lineas
	{
		j = 0;
		while (j < (int)ft_strlen(raw->map[i]))
		{
			if (raw->map[i][0] != '1' || raw->map[0][j] != '1')
			{
				printf("Error. Your map must be completly enclosed by walls");
				return (-1);
			}
			if (raw->map[i][ft_strlen(raw->map[i]) - 1] != '1' || raw->map[raw->rows - 1][j] != '1')
			{
				printf("Error. Your map must be completly enclosed by walls");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		flood_fill(mapstr *raw, int y, int x)
{
	if (ft_strchr("NSWE0", raw->map[y][x]))
		raw->map[y][x] = '3';

	if(raw->map[y - 1][x] == '0')
		flood_fill(raw, y - 1, x);
	if(raw->map[y][x + 1] == '0')
		flood_fill(raw, y, x + 1);
	if(raw->map[y + 1][x] == '0')
		flood_fill(raw, y + 1, x);
	if(raw->map[y][x - 1] == '0')
		flood_fill(raw, y, x - 1);

	if (raw->map[y][x] == '\0')
	{
		printf("ERROR. You need to introduce a correct map");
		return (-1);
	}

	return (1);
}

int		check_map(mapstr *raw, mapclean *map)
{
	map = NULL;
	if (find_origin(raw) == -1)
		return (-1);
	if (check_border(raw) == -1)
		return (-1);
	if (flood_fill(raw, raw->y , raw->x) == -1)
		return (-1);
	return (1);
}
