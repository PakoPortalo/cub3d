/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_map_clean.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:11:02 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/18 17:35:41 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char			*handle_resolution_spaces(char *line)
{
	char		*temp;

	temp = line;
	while (temp[0] == ' ' || temp[0] == '\t')
	{
		if (temp[0] == ' ')
			temp = ft_strtrim(temp, " ");
		if (temp[0] == '\t')
			temp = ft_strtrim(temp, "\t");
	}
	return (temp);
}

void		check_res_arguments(char **resolution)
{
	if (resolution[3])
	{
		perror("Error\nIntroduced bad resolution.\n");
		exit(3);
	}
	if (ft_atoi(resolution[1]) <= 0 || ft_atoi(resolution[2]) <= 0
		|| ft_atoi(resolution[1]) > INT32_MAX || \
		ft_atoi(resolution[2]) > INT32_MAX)
	{
		perror("Error\nResolution can't be negative, zero or too big\n");
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
	resolution[1] = handle_resolution_spaces(resolution[1]);
	resolution[2] = handle_resolution_spaces(resolution[2]);
	check_res_isdigit(resolution);
	map->w = ft_atoi(resolution[1]);
	map->h = ft_atoi(resolution[2]);
	ft_freearray(resolution);
}
