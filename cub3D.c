/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:04:24 by fportalo          #+#    #+#             */
/*   Updated: 2021/01/07 10:34:52 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				cub3d(int argc, char **argv)
{
	mapstr		raw;
	mapclean	map;

	check_ini_errors(argc, argv);
	raw_info(argv[1], &raw);
	map.map = raw.map;
	save_map_info(&raw, &map);
	printer_cub3d(&map);
	return (0);
}
