/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:04:24 by fportalo          #+#    #+#             */
/*   Updated: 2020/12/04 13:11:53 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		cub3d(int argc, char **argv)
{
	mapstr raw;
	mapclean map;
	int i = 0;

	check_ini_errors(argc, argv);
	raw_info(argv[1], &raw);
	save_map_info(&raw, &map);

	while (raw.rows != 0)
	{
		printf("%s\n", raw.map[i]);
		i++;
		raw.rows--;
	}
	return (0);
}
