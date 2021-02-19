/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_map_clean.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:11:02 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/19 12:13:32 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_res_arguments(char **resolution)
{
	if (resolution[3])
	{
		perror("Error\nIntroduced bad resolution.\n");
		exit(3);
	}
	if (ft_atoi(resolution[1]) <= 0 || ft_atoi(resolution[2]) <= 0)
	{
		perror("Error\nResolution can't be negative, zero or massive.\n");
		exit(3);
	}
}

void		check_res_isdigit(char **resolution)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (resolution[i] != NULL)
	{
		j = 0;
		while (resolution[i][j] != '\0')
		{
			if (!ft_isdigit(resolution[i][j]))
			{
				perror("Error\nResolution is not a valid number.\n");
				exit(3);
			}
			j++;
		}
		i++;
	}
}

void		check_resolution(t_mapstr *raw, t_mapclean *map)
{
	char	**resolution;

	resolution = ft_split(raw->res, ' ');
	check_res_arguments(resolution);
	check_res_isdigit(resolution);
	map->w = ft_atoi(resolution[1]);
	map->h = ft_atoi(resolution[2]);
	ft_freearray(resolution);
}
