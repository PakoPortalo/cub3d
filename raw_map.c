/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:18:41 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/23 13:08:12 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int			check_number_lines(mapstr *raw)
{
	if (!raw->res || !raw->north || !raw->south || !raw->west || !raw->east ||\
		!raw->sprite || !raw->floor || !raw->ceil || !raw->map || !raw->rows)
		{
			printf("Map file error.\nPlease introduce a correct number of arguments\n");
			return (-1);
		}
	return (1);
}

void		get_map(mapstr *raw, char *line, char *file)
{
	int fd;
	int i;

	i = 0;
	raw->map = (char **)malloc(sizeof(char *) * raw->rows + 1);
	raw->map[raw->rows + 1] = NULL;
	fd = open(file, O_RDONLY);
	while((get_next_line(fd, &line)) > 0)
	{
		if (!ft_strchr("RNSWESFC", *line))
		{
			if (!raw->map)
			{
				raw->map[i] = ft_strdup(line);
				raw->map[i][ft_strlen(line)] = '\0';
			}
			else
			{
				raw->map[i] = ft_strdup(line);
				raw->map[i][ft_strlen(line)] = '\0';
			}
			i++;
		}
		raw->map[i] = NULL;

	}
	free(line);
	close(fd);
}

void		iniraw(mapstr *raw)
{
	raw->res = NULL;
	raw->north = NULL;
	raw->south = NULL;
	raw->west = NULL;
	raw->east = NULL;
	raw->sprite = NULL;
	raw->floor = NULL;
	raw->ceil = NULL;
	raw->map = NULL;
	raw->rows = 0;
	raw->err = 0;
}

void		get_raw_line(mapstr *raw, char *file)
{
	char *line;
	int	fd;

	fd = open(file, O_RDONLY);
	line = NULL;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (line[0] == 'R')
			raw->res = ft_strdup(line);
		else if(line[0] == 'N')
			raw->north = ft_strdup(line);
		else if(line[0] == 'S' && line[1] == 'O')
			raw->south = ft_strdup(line);
		else if (line[0] == 'W')
			raw->west = ft_strdup(line);
		else if (line[0] == 'E')
			raw->east = ft_strdup(line);
		else if (line[0] == 'S')
			raw->sprite = ft_strdup(line);
		else if (line[0] == 'F')
			raw->floor = ft_strdup(line);
		else if (line[0] == 'C')
			raw->ceil = ft_strdup(line);
		else if (line[0] == '0' || line[0] == '1' || line[0] == '2')
			raw->rows++;
	}
	free(line);
	close(fd);
	get_map(raw, line, file);
}

int			raw_info(char *file, mapstr *raw)
{
	iniraw(raw);
	get_raw_line(raw, file);
	if (check_number_lines(raw) == -1)
		return (-1);
	return (1);
}
