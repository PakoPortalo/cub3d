/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamagotchi <tamagotchi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:04:24 by fportalo          #+#    #+#             */
/*   Updated: 2020/12/20 12:42:41 by tamagotchi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int		cub3d(int argc, char **argv)
{
	mapstr raw;
	mapclean map;
	check_ini_errors(argc, argv);
	raw_info(argv[1], &raw);
	save_map_info(&raw, &map);
	map.map = raw.map;
	//printer_cub3d(&map);
	return (0);
}
