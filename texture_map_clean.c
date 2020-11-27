/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map_clean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:09:21 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/27 12:48:55 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
int		check_texture_path(mapclean *map)
{

}
*/
int		check_texture_extension(mapclean *map)
{
	if (check_extension(map->north, ".xpm") == -1)
		return (-1);
	if (check_extension(map->south, ".xpm") == -1)
		return (-1);
	if (check_extension(map->west, ".xpm") == -1)
		return (-1);
	if (check_extension(map->east, ".xpm") == -1)
		return (-1);
	if (check_extension(map->sprite, ".xpm") == -1)
		return (-1);
	return (1);
}

int		number_textures(char **texture)
{
	if (texture[2])
	{
		printf("Error. Number of texture arguments wrong\n");
		return (-1);
	}
	return (1);
}

int		get_texture(mapstr *raw, mapclean *map)
{
	char **texture;

	texture = ft_split(raw->north, ' ');
	if (number_textures(texture) == -1)
		return(-1);
	map->north = texture[1];
	texture = ft_split(raw->south, ' ');
	if (number_textures(texture) == -1)
		return(-1);
	map->south = texture[1];
	texture = ft_split(raw->west, ' ');
	if (number_textures(texture) == -1)
		return(-1);
	map->west = texture[1];
	texture = ft_split(raw->east, ' ');
	if (number_textures(texture) == -1)
		return(-1);
	map->east = texture[1];
	texture = ft_split(raw->sprite, ' ');
	if (number_textures(texture) == -1)
		return(-1);
	map->sprite = texture[1];

	return (1);
}

int		check_texture(mapstr *raw, mapclean *map)
{
		if (get_texture(raw, map) == -1)
			return (-1);
		if (check_texture_extension(map) == -1)
			return (-1);
		/*if (check_texture_path(map) == -1)
			return (-1);
*/


		printf("%s\n", map->north);
		printf("%s\n", map->south);
		printf("%s\n", map->west);
		printf("%s\n", map->east);
		printf("%s\n", map->sprite);
		return (1);
}
