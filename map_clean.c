/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:06:44 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/24 13:11:02 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		save_map_info(mapstr *raw, mapclean *map)
{
	inimap(map);
	if (check_resolution(raw, map) == -1)
		return (-1);
	if (check_texture(raw, map) == -1)
		return (-1);
	return (1);
}
