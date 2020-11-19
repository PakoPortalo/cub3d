/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:44:22 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/19 12:37:39 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Inicia la estructura mapinf
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
	map.rows = 0;
	return (map);
}

//Función especial para alocar y guardar el mapa en una matriz char[i][j]
//Siendo [i] las columnas y [j] las líneas
mapinf		getmap(mapinf map, char *line, char *file)
{
	int fd;
	int i;

	i = 0;
	map.map = (char **)malloc(sizeof(char *) * map.rows + 1);
	map.map[map.rows + 1] = NULL;
	fd = open(file, O_RDONLY);
	while((get_next_line(fd, &line)) > 0)
	{
		if (!ft_strchr("RNSWESFC", *line))
		{
			if (!map.map)
			{
				map.map[i] = ft_strdup(line);
				map.map[i][ft_strlen(line)] = '\0';
			}
			else
			{
				map.map[i] = ft_strdup(line);
				map.map[i][ft_strlen(line)] = '\0';
			}
			i++;
		}
		map.map[i] = NULL;

	}
	free(line);
	close(fd);
	return (map);
}

//Guarda linea por linea la información del mapa en la estructura mapinf
mapinf		getmapinf(char *line, mapinf map, int fd, char *file)
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
		else if (line[0] == '0' || line[0] == '1' || line[0] == '2')
			map.rows++;
	}
	free(line);
	close(fd);
	map = getmap(map, line, file);
	return (map);
}


int get_map_line(char *file)
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
		printf("No funciona.\n");
		return(0);
	}
	else
		map = getmapinf(line, map, fd, file);

	if (map_elements(map) == -1)
	{
		printf("Mapa roto.\n");
		return(-1);
	}

	while (map.rows != 0)					// test
	{
		map.rows--;
		printf("%s\n", map.map[i]);
		i++;
	}
	free(line);
	close(fd);
	return (0);
}
