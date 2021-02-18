/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map_clean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:09:21 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/18 17:33:50 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_texture_path(char *texturepath)
{
	int		fd;

	if ((fd = open(texturepath, O_RDONLY)) == -1)
	{
		perror("Error\nCannot find textures");
		close(fd);
		exit(4);
	}
	close(fd);
}

int			check_texture_extension(t_mapclean *map)
{
	if (check_extension(map->north, ".xpm") == -1 && \
	check_extension(map->north, ".png") == -1)
		return (-1);
	if (check_extension(map->south, ".xpm") == -1 && \
	check_extension(map->south, ".png") == -1)
		return (-1);
	if (check_extension(map->west, ".xpm") == -1 && \
	check_extension(map->west, ".png") == -1)
		return (-1);
	if (check_extension(map->east, ".xpm") == -1 && \
	check_extension(map->east, ".png") == -1)
		return (-1);
	if (check_extension(map->sprite, ".xpm") == -1 && \
	check_extension(map->sprite, ".png") == -1)
		return (-1);
	return (1);
}

void		check_texture(t_mapstr *raw, t_mapclean *map)
{
	get_texture(raw, map);
	if (check_texture_extension(map) == -1)
	{
		perror("Error\nPlease introduce a valid extension");
		exit(1);
	}
	check_texture_path(map->north);
	check_texture_path(map->south);
	check_texture_path(map->west);
	check_texture_path(map->east);
	check_texture_path(map->sprite);
}
