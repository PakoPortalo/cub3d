/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:44:22 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/17 13:31:14 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mapinf		inimap()
{
	mapinf map;

	map.res = NULL;
	map.north = NULL;
	map.south = NULL;
	map.west = NULL;
	map.east = NULL;
	map.sprite = NULL;
	map.floor = NULL;
	map.ceil = NULL;
	map.map = NULL;
	return (map);
}
mapinf		getmap(mapinf map, char *line)
{
	if (!map.map)
	{
		map.map = line;
		map.map[ft_strlen(map.map)] = '\n';
	}
	else
	{
		map.map = ft_strjoin(map.map, line);
		map.map[ft_strlen(map.map)] = '\n';
	}
	map.map[ft_strlen(map.map)] = '\0';
	return (map);
}

mapinf		getmapinf(char *line, mapinf map, int fd)
{
	while ((get_next_line(fd, &line)) > 0)
	{
		if (line[0] == 'R')
			map.res = line;
		else if(line[0] == 'N')
			map.north = line;
		else if(line[0] == 'S' && line[1] == 'O')
			map.south = line;
		else if (line[0] == 'W')
			map.west = line;
		else if (line[0] == 'E')
			map.east = line;
		else if (line[0] == 'S')
			map.sprite = line;
		else if (line[0] == 'F')
			map.floor = line;
		else if (line[0] == 'C')
			map.ceil = line;
		else if (line[0] == '1')
			map = getmap(map, line);
	}
	return (map);
}

int parse_map(char *file)
{
	int		fd;
	char	*line = NULL;
	int		i;
	mapinf	map;


	i = 0;
	map = inimap();
	fd = open(file, O_RDONLY);

	if (fd == -1)
	{
		printf("No funciona\n");
		return(0);
	}
	else
		map = getmapinf(line, map, fd);
	printf("%s\n", map.map);
	free(line);
	close(fd);
	return (0);
}
