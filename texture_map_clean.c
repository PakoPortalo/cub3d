/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map_clean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamagotchi <tamagotchi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:09:21 by fportalo          #+#    #+#             */
/*   Updated: 2020/12/20 12:46:17 by tamagotchi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_texture_path(char *texturepath)
{
	int fd;

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
	if (check_extension(map->north, ".xpm") == -1 && check_extension(map->north, ".png") == - 1)
		return (-1);
	if (check_extension(map->south, ".xpm") == -1 && check_extension(map->south, ".png") == - 1)
		return (-1);
	if (check_extension(map->west, ".xpm") == -1 && check_extension(map->west, ".png") == -1 )
		return (-1);
	if (check_extension(map->east, ".xpm") == -1 && check_extension(map->east, ".png") == -1)
		return (-1);
	if (check_extension(map->sprite, ".xpm") == -1 && check_extension(map->sprite, ".png") == -1)
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

char	*check_spaces(char *texturepath)
{
	while (texturepath[0] == ' ' || texturepath[0] == '\t' || \
	texturepath[ft_strlen(texturepath) - 1] == ' ' || texturepath[ft_strlen(texturepath) - 1] == '\t')
	{
		texturepath = ft_strtrim(texturepath, " ");
		texturepath = ft_strtrim(texturepath, "\t");
	}
	return(texturepath);
}

void		get_texture(mapstr *raw, mapclean *map)
{
	char **texture;

	raw->north = check_spaces(raw->north);
	texture = ft_split(raw->north, ' ');
	number_textures(texture);
	texture[1] = check_spaces(texture[1]);
	map->north = ft_strdup(texture[1]);
	ft_freearray(texture);
	
	raw->south = check_spaces(raw->south);
	texture = ft_split(raw->south, ' ');
	number_textures(texture);
	texture[1] = check_spaces(texture[1]);
	map->south = ft_strdup(texture[1]);
	ft_freearray(texture);

	raw->west = check_spaces(raw->west);
	texture = ft_split(raw->west, ' ');
	number_textures(texture);
	texture[1] = check_spaces(texture[1]);
	map->west = ft_strdup(texture[1]);
	ft_freearray(texture);

	raw->east = check_spaces(raw->east);
	texture = ft_split(raw->east, ' ');
	number_textures(texture);
	texture[1] = check_spaces(texture[1]);
	map->east = ft_strdup(texture[1]);
	ft_freearray(texture);

	raw->sprite = check_spaces(raw->sprite);
	texture = ft_split(raw->sprite, ' ');
	number_textures(texture);
	texture[1] = check_spaces(texture[1]);
	map->sprite = ft_strdup(texture[1]);
		ft_freearray(texture);
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
