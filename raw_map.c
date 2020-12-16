/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:18:41 by fportalo          #+#    #+#             */
/*   Updated: 2020/12/15 12:35:51 by fportalo         ###   ########.fr       */
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

char *			handle_spaces(char *line)
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
		line = handle_spaces(line);
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
	}
	raw->map[i] = ft_strdup(line);
	if (line[0] != '\0')
		raw->rows++;
	free(line);
	close(fd);
}


void		get_raw_line(mapstr *raw, char *file, mapconfig *num)
{
	char *line;
	int	fd;
	int i;
	fd = open(file, O_RDONLY);
	line = NULL;
	while ((i = get_next_line(fd, &line)) > 0)
	{		if (line[0] == ' ' || line[0] == '\t')
			line = handle_spaces(line);
		if (!ft_strncmp(line, "R ", 2))
		{
			raw->res = ft_strdup(line);
			num->res += 1;
		}
		else if (!ft_strncmp(line, "NO ", 3))
		{
			raw->north = ft_strdup(line);
			num->north += 1;
		}
		else if (!ft_strncmp(line, "SO ", 3))
		{
			raw->south = ft_strdup(line);
			num->south += 1;
		}
		else if (!ft_strncmp(line, "WE ", 3))
		{
			raw->west = ft_strdup(line);
			num->west += 1;
		}
		else if (!ft_strncmp(line, "EA ", 3))
		{
			raw->east = ft_strdup(line);
			num->east += 1;
		}
		else if (!ft_strncmp(line, "S ", 2))
		{
			raw->sprite = ft_strdup(line);
			num->sprite += 1;
		}
		else if (!ft_strncmp(line, "C ", 2))
		{
			raw->floor = ft_strdup(line);
			num->floor += 1;
		}
		else if (!ft_strncmp(line, "F ", 2))
		{
			raw->ceil = ft_strdup(line);
			num->ceil += 1;
		}
		else if (line[0] == '0' || line[0] == '1' || line[0] == '2' || line[0] == ' ')
			raw->rows++;
		else if (line[0] != '\0')
		{
			perror("Error\nMap file error. Please introduce valid arguments\n");
			exit (2);
		}
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
