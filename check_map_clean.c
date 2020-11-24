/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:11:02 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/24 12:11:12 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_nbrdigit (int i)
{
	int		d;

	d = 0;
	while (i != 0)
	{
		i = i / 10;
		d++;
	}
	return (d);
}

int		check_res(mapstr *raw, mapclean *map)
{
	int i;

	i = 2;
	if (!(raw->res[0] == 'R' && raw->res[1] == ' ') && ft_strchr("1234567890", raw->res[2]))
	{
		printf("Error. Introduced bad resolution\n");
		return (-1);
	}
	map->w = ft_atoi(&raw->res[i]);
	i += ft_nbrdigit(map->w);
	if (!(raw->res[i] = ' ' && ft_strchr("1234567890", raw->res[i + 1])))
	{
		printf("Error. Introduced bad resolution\n");
		return (-1);
	}
	map->h = ft_atoi(&raw->res[i + 1]);
	i += ft_nbrdigit(map->h);
	if (!(raw->res[i + 1] == '\0'))
	{
		printf("Error. Introduced bad resolution\n");
		return (-1);
	}
	return (1);
}
