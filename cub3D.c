/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:04:24 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/18 17:41:18 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				cub3d(int argc, char **argv)
{
	t_mapstr	raw;
	t_mapclean	map;

	inimap(&map);
	check_ini_errors(argc, argv, &map);
	raw_info(argv[1], &raw, &map);
	map.map = raw.map;
	save_map_info(&raw, &map);
	printer_cub3d(&map);
	return (0);
}
