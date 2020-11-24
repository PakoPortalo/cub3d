/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:04:24 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/24 12:47:10 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		cub3d(int argc, char **argv)
{
	mapstr raw;
	mapclean map;
	//int i = 0;

	if (check_ini_errors(argc, argv) == -1)
		return (-1);
	if (raw_info(argv[1], &raw) == -1)
		return (-1);
	if (save_map_info(&raw, &map) == -1)
		return (-1);
	/*
	while(raw.rows != 0)
	{
		raw.rows--;
		printf("%s\n", raw.map[i]);
		i++;
	}
	printf("%d\n", map.w);
	printf("%d\n", map.h);
	*/
	return (0);
}
