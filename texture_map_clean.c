/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map_clean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:09:21 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/24 13:30:00 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_north(mapstr *raw, mapclean *map)
{
	int		i;
	int		j;
	char	*ext;

	i = ft_strlen(raw->north) - 4;
	j = 0;
	ext = ".xpm";
	if (!(raw->north[0] == 'N' && raw->north[1] == 'O' && raw->north[1] == ' ') &&\
	raw->north[2] == '.' && raw->north[3] == '/')
	{
		printf("Error. Introduce a correct North Texture\n");
		return (-1);
	}
	while (raw->north[i] != '\0')
	{
		if (raw->north[i] != ext[j])
		{
			printf("Error. The north texture file extension is not correct\n");
			return (-1);
		}
		i++;
		j++;
	}
	raw->north += 3;
	map->north = raw->north;
	return (1);
}

int		check_texture(mapstr *raw, mapclean *map)
{
	check_north(raw, map);
	return (1);
}
