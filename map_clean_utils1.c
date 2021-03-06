/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_clean_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 10:39:38 by fportalo          #+#    #+#             */
/*   Updated: 2020/12/21 12:48:55 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_number_variables(char **rgb, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		if (!rgb[j])
		{
			perror("Error\nNumber of floor/ceil arguments wrong\n");
			exit(5);
		}
		j++;
	}
	if (rgb[i])
	{
		perror("Error\nNumber of floor/ceil arguments wrong\n");
		exit(5);
	}
}

void		comma_counter(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
	{
		perror("Error\nNumber of floor/ceil arguments wrong\n");
		exit(5);
	}
}

char		*floor_ceil_spaces(char *rgb)
{
	while (rgb[0] == ' ' || rgb[0] == '\t' || \
	rgb[ft_strlen(rgb) - 1] == ' ' || rgb[ft_strlen(rgb) - 1] == '\t')
	{
		rgb = ft_strtrim(rgb, " ");
		rgb = ft_strtrim(rgb, "\t");
	}
	return (rgb);
}

char		*get_map_texture(char *rawtexture, char *maptexture)
{
	char **texture;

	rawtexture = check_spaces(rawtexture);
	texture = ft_split(rawtexture, ' ');
	number_textures(texture);
	texture[1] = check_spaces(texture[1]);
	maptexture = ft_strdup(texture[1]);
	ft_freearray(texture);
	return (maptexture);
}

void		get_texture(mapstr *raw, mapclean *map)
{
	map->north = get_map_texture(raw->north, map->north);
	map->south = get_map_texture(raw->south, map->south);
	map->west = get_map_texture(raw->west, map->west);
	map->east = get_map_texture(raw->east, map->east);
	map->sprite = get_map_texture(raw->sprite, map->sprite);
}
