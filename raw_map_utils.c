/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:41:55 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/18 18:46:22 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			check_number_lines(t_mapstr *raw, t_mapconfig *num, t_mapclean *map)
{
	int			i;

	i = 0;
	map->rows = raw->rows;
	if (!raw->res || !raw->north || !raw->south || !raw->west || !raw->east || \
	!raw->sprite || !raw->floor || !raw->ceil || !raw->map || !raw->rows || \
	num->res != 1 || num->north != 1 || num->south != 1 || num->west != 1 || \
	num->east != 1 || num->sprite != 1 || num->floor != 1 || num->ceil != 1)
	{
		perror("Error\nPlease introduce arguments correctly\n");
		exit(2);
	}
}

void			get_raws(char **path, int *num, char *line)
{
	*path = ft_strdup(line);
	*num += 1;
}

void			map_file_error(void)
{
	perror("Error\nMap file error. Please introduce valid arguments\n");
	exit(2);
}
