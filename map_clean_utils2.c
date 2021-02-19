/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_clean_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:44:28 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/19 17:00:51 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		number_textures(char **texture)
{
	if (texture[2])
	{
		perror("Error\nNumber of texture arguments wrong\n");
		exit(4);
	}
}

char		*check_spaces(char *texturepath)
{
	int i;

	i = 0;
	while (texturepath[i] != ' ' && (i != 1 || i != 2))
		i++;
	while (texturepath[i] == ' ' || texturepath[i] == '\t')
		i++;
	return (texturepath + i);
}

void		get_coordinates(int *x, int *y, t_mapstr *raw, t_mapclean *map)
{
	if (!*x && !*y)
	{
		map->x = raw->x;
		map->y = raw->y;
		*x = raw->x;
		*y = raw->y;
	}
}

void		check_border(t_mapstr *raw, int y, int x)
{
	if (y <= 0 || y >= (raw->rows - 1) || x <= 0 || \
	x >= ((int)ft_strlen(raw->map[y]) - 1))
	{
		perror("Error\nYou need to introduce a correct map\n");
		exit(6);
	}
}

void		get_map_utils(t_mapstr *raw, char **line, int fd, int check)
{
	int		i;

	i = 0;
	while ((get_next_line(fd, line)) > 0)
	{
		if (*line[0] == '\0' && check == 1)
		{
			i--;
			*line = ft_strdup(" ");
		}
		if (!ft_strchr("RNSWESFC", **line))
		{
			if (*line[0] == '1')
				check = 1;
			if (!raw->map)
				raw->map[i] = ft_strdup(*line);
			else if (raw->map)
				raw->map[i] = ft_strdup(*line);
			i++;
		}
		free(*line);
	}
	raw->map[i] = ft_strdup(*line);
	free(*line);
	close(fd);
}
