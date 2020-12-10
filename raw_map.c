/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:18:41 by fportalo          #+#    #+#             */
/*   Updated: 2020/12/10 10:47:15 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void			check_number_lines(mapstr *raw, mapconfig *num)
{
	int i = 0;

	if (!raw->res || !raw->north || !raw->south || !raw->west || !raw->east ||\
		!raw->sprite || !raw->floor || !raw->ceil || !raw->map || !raw->rows ||\
		num->res != 1 || num->north != 1 || num->south != 1 || num->west != 1 || num->east != 1 || \
		num->sprite != 1 || num->floor != 1 || num->ceil != 1)
		{
			while (raw->rows != 0)
			{
				printf("%s\n", raw->map[i]);
				i++;
				raw->rows--;
			}
			perror("Error\nMap file error. Please introduce a correct number of arguments\n");
			exit (2);
		}
}

char *			handle_spaces(mapstr *raw, char *line, int i)
{
	char *temp;

	temp = line;
	while (temp[0] == ' ' || temp[0] == '\t')
	{
		if (temp[0] == ' ')
			temp = ft_strtrim(temp, " ");
		if (temp[0] == '\t')
			temp = ft_strtrim(temp, "\t");
	}
	if ((temp[0] == '0' || temp[0] == '1'))
	{
		if (i == 0)
			raw->rows++;
		return(line);
	}
	return(temp);
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
		line = handle_spaces(raw, line, 1);
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
	if (line[0] != '\0')
	{
		raw->map[i] = "\0";
		raw->rows++;
	}
	free(line);
	close(fd);
}


void		get_raw_line(mapstr *raw, char *file, mapconfig *num)  // TIO HE INTENTADO METER num->loquesea dentro de los if pero no me funcionaba
{
	char *line;
	int	fd;

	fd = open(file, O_RDONLY);
	line = NULL;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (line[0] == ' ' || line[0] == '\t')
			line = handle_spaces(raw, line, 0);
		if (line[0] == 'R' && line[1] == ' ')
		{
			raw->res = ft_strdup(line);
			num->res += 1;
		}
		else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		{
			raw->north = ft_strdup(line);
			num->north += 1;
		}
		else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		{
			raw->south = ft_strdup(line);
			num->south += 1;
		}
		else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		{
			raw->west = ft_strdup(line);
			num->west += 1;
		}
		else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		{
			raw->east = ft_strdup(line);
			num->east += 1;
		}
		else if (line[0] == 'S' && line[1] == ' ')
		{
			raw->sprite = ft_strdup(line);
			num->sprite += 1;
		}
		else if (line[0] == 'F' && line[1] == ' ')
		{
			raw->floor = ft_strdup(line);
			num->floor += 1;
		}
		else if (line[0] == 'C' && line[1] == ' ')
		{
			raw->ceil = ft_strdup(line);
			num->ceil += 1;
		}
		else if (line[0] == '0' || line[0] == '1')
			raw->rows++;
	}
	free(line);
	close(fd);
	get_map(raw, line, file);
}

void			raw_info(char *file, mapstr *raw)
{
	mapconfig num;

	iniraw(raw);
	ininum(&num);
	get_raw_line(raw, file, &num);
	check_number_lines(raw, &num);
}
