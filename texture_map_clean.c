/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map_clean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:09:21 by fportalo          #+#    #+#             */
/*   Updated: 2020/12/07 09:54:24 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_texture_path(char *texturepath)
{
	int fd;

	fd = open(texturepath, O_RDONLY);
	if ((fd = open(texturepath, O_RDONLY)) == -1)
	{
		perror("Error\nCannot find textures");
		close(fd);
		exit (4);
	}
	close(fd);
}


int		check_texture_extension(mapclean *map)
{
	if (!check_extension(map->north, ".xpm") && !check_extension(map->north, ".png"))
		return (-1);
	if (!check_extension(map->south, ".xpm") && !check_extension(map->south, ".png"))
		return (-1);
	if (!check_extension(map->west, ".xpm") && !check_extension(map->west, ".png"))
		return (-1);
	if (!check_extension(map->east, ".xpm") && !check_extension(map->east, ".png"))
		return (-1);
	if (!check_extension(map->sprite, ".xpm") && !check_extension(map->sprite, ".png"))
		return (-1);
	return (1);
}

void	number_textures(char **texture)
{
	if (texture[2])
	{
		perror("Error\nNumber of texture arguments wrong\n");
		exit (4);
	}
}

void		get_texture(mapstr *raw, mapclean *map)
{
	char **texture;

	texture = ft_split(raw->north, ' ');
	number_textures(texture);
	map->north = texture[1];
	texture = ft_split(raw->south, ' ');
	number_textures(texture);
	map->south = texture[1];
	texture = ft_split(raw->west, ' ');
	number_textures(texture);
	map->west = texture[1];
	texture = ft_split(raw->east, ' ');
	number_textures(texture);
	map->east = texture[1];
	texture = ft_split(raw->sprite, ' ');
	number_textures(texture);
	map->sprite = texture[1];
}

void		check_texture(mapstr *raw, mapclean *map)
{
		get_texture(raw, map);
		if (check_texture_extension(map) == -1)
		{
			perror("Error\nPlease introduce a valid extension");
			exit (1);
		}
		check_texture_path(map->north);
		check_texture_path(map->south);
		check_texture_path(map->west);
		check_texture_path(map->east);
		check_texture_path(map->sprite);
}
