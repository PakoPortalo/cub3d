/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:18:04 by fportalo          #+#    #+#             */
/*   Updated: 2020/12/01 13:15:24 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// PROBLEMA EN FIND_ORIGIN CON EL STRCHAR, TENGO QUE HACER 4 IFS PORQUE SI NO NO ME FUNCIONA WTF NIGGA

int	find_origin(mapstr *raw)
{
	while (raw->x < (int)ft_strlen(raw->map[raw->y]) && raw->y < (raw->rows - 1)) // NO FUNCIONA EL CASO DE QUE HAYAN 2 PUNTOS
	{
		while (raw->map[raw->y][raw->x])
		{
			if (ft_strchr("NSWE", raw->map[raw->y][raw->x]))
				break;
			raw->x++;
		}
		if (raw->map[raw->y][raw->x] == 'N')
			return (1);
		if (raw->map[raw->y][raw->x] == 'S')
			return (1);
		if (raw->map[raw->y][raw->x] == 'W')
			return (1);
		if (raw->map[raw->y][raw->x] == 'E')
			return (1);
		raw->y++;
		raw->x = 0;
	}
		printf("Error. There is no player. Map need an origin point (N, S, W, E)\n");
		return (-1);
}

int		flood_fill(mapstr *raw, int x, int y)
{
	if (raw->map[y][x] == '0' || ft_strchr("NSWE", raw->map[y][x]))
		raw->map[y][x] = '3';
	if (raw->map[y][x - 1] == '0')
		flood_fill(raw, y, x - 1);
	if (raw->map[y + 1][x] == '0')
		flood_fill(raw, y + 1, x);
	if (raw->map[y][x + 1] == '0')
		flood_fill(raw,y, x + 1);
	if (raw->map[y - 1][x] == '0')
		flood_fill(raw, y -1, x);
	return (1);

}

int		check_map(mapstr *raw, mapclean *map)
{
	map = NULL;
	if (find_origin(raw) == -1)
		return (-1);
	if (flood_fill(raw, raw->x, raw->y) == -1)
		return (-1);
	return (1);
}
