/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:01:16 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/19 12:50:01 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Si encuentra un caracter en el mapa que no se encuentre en "012 NSEW" Devuelve error
int			map_elements(mapinf map)
{
	int i;
	int j;

	i = 0;
	while (map.map[i] != '\0')
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] != '0' && map.map[i][j] != '1' && map.map[i][j] != '2' && \
				map.map[i][j] != 'N' && map.map[i][j] != 'S' && map.map[i][j] != 'E' && \
				map.map[i][j] != 'W' && map.map[i][j] != ' ')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int			check_map(mapinf map)
{

}
