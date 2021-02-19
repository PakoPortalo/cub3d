/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:18:41 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/19 16:57:18 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char			*handle_spaces(char *line)
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
	if (temp[0] == '1')
		return (line);
	return (temp);
}

void			get_map(t_mapstr *raw, char *line, char *file)
{
	int			fd;
	int			i;
	int			check;

	check = 0;
	i = 0;
	raw->map = (char **)ft_calloc(sizeof(char *), (raw->rows + 2));
	fd = open(file, O_RDONLY);
	get_map_utils(raw, &line, fd, check);
}

void			handle_num_errors(t_mapstr *raw, t_mapconfig *num)
{
	if ((num->res + num->north + num->south + num->west + \
	num->east + num->sprite + num->floor + num->ceil) != 8)
	{
		perror("Error, bad values sent in your .cub");
		exit(1);
	}
	raw->rows++;
}

void			raw_stuff(t_mapstr *raw, t_mapconfig *num, char *line)
{
	if (line[0] == ' ' || line[0] == '\t')
		line = handle_spaces(line);
	if (!ft_strncmp(line, "R ", 2))
		get_raws(&raw->res, &num->res, line);
	else if (!ft_strncmp(line, "NO ", 3))
		get_raws(&raw->north, &num->north, line);
	else if (!ft_strncmp(line, "SO ", 3))
		get_raws(&raw->south, &num->south, line);
	else if (!ft_strncmp(line, "WE ", 3))
		get_raws(&raw->west, &num->west, line);
	else if (!ft_strncmp(line, "EA ", 3))
		get_raws(&raw->east, &num->east, line);
	else if (!ft_strncmp(line, "S ", 2))
		get_raws(&raw->sprite, &num->sprite, line);
	else if (!ft_strncmp(line, "C ", 2))
		get_raws(&raw->ceil, &num->ceil, line);
	else if (!ft_strncmp(line, "F ", 2))
		get_raws(&raw->floor, &num->floor, line);
	else if (line[0] == '0' || line[0] == '1' || \
	line[0] == '2' || line[0] == ' ')
		handle_num_errors(raw, num);
	else if (line[0] != '\0')
		map_file_error();
	free(line);
}

void			raw_info(char *file, t_mapstr *raw, t_mapclean *map)
{
	t_mapconfig	num;
	char		*line;
	int			fd;

	iniraw(raw);
	ininum(&num);
	fd = open(file, O_RDONLY);
	line = NULL;
	while ((get_next_line(fd, &line)) > 0)
		raw_stuff(raw, &num, line);
	raw_stuff(raw, &num, line);
	close(fd);
	get_map(raw, line, file);
	check_number_lines(raw, &num, map);
}
