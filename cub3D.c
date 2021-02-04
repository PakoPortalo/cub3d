/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:04:24 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/04 13:29:42 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void			ft_printmap(char **map, int rows)
// {
// 	int i;
// 	i = 0;
// 	while (i < rows)
// 	{
// 		printf("%s\n", map[i]);
// 		i++;
// 	}
// 	// printf("%s\n", map[i]);
// }

int				cub3d(int argc, char **argv)
{
	mapstr		raw;
	mapclean	map;

	inimap(&map);
	check_ini_errors(argc, argv);
	raw_info(argv[1], &raw);
	// map.map = ft_arraydup(raw.map, raw.rows);
	map.map = raw.map;
	// ft_printmap(map.map, raw.rows);
	save_map_info(&raw, &map);
	printer_cub3d(&map);
	return (0);
}