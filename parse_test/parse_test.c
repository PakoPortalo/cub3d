/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:44:22 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/16 11:32:28 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_test.h"

mapdef		inimap()
{
	mapdef map;

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

mapdef		getmapinf(char *line, mapdef map, int fd)
{
	int		lmap;

	lmap = 0;
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
		}
	}
	return (map);
}

int parse_test(char *file)
{
	int		fd;
	char	*line = NULL;
	int		i;
	mapdef	map;


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
	printf("%s\n", map.res);
	printf("%s\n", map.north);
	printf("%s\n", map.south);
	printf("%s\n", map.west);
	printf("%s\n", map.east);
	printf("%s\n", map.sprite);
	printf("%s\n", map.floor);
	printf("%s\n", map.ceil);
	printf("%s\n", map.map);
	free(line);
	close(fd);
	return (0);
}
