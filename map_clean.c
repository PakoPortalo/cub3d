/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:06:44 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/17 19:36:12 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		free_raw(mapstr *raw)
{
	free(raw->res);
	free(raw->north);
	free(raw->south);
	free(raw->west);
	free(raw->east);
	free(raw->sprite);
	free(raw->floor);
	free(raw->ceil);
}

void		save_map_info(mapstr *raw, mapclean *map)
{
	check_resolution(raw, map);
	check_texture(raw, map);
	check_floor_ceil(raw, map);
	check_map(raw, map);
	free_raw(raw);
}
