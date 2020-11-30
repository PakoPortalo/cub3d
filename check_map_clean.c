/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:18:04 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/30 11:02:33 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_map(mapstr *raw, mapclean *map)
{
	int i;
	int j;

	i = 0;
	map = NULL;
	while (raw->map[i])
	{
		j = 0;
		while (raw->map[i][j])
		{
			if (raw->map[0][j] != '1' && raw->map[i][0] != '1')
			{
				printf("MUERTE 1\n");
				return (-1);
			}
			if (raw->map[i][ft_strlen(raw->map[i]) - 1] != '1' && raw->map[ft_strlen(raw->map[j] - 1)][j] != '1')
			{
				printf("MUERTE 2\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	printf("VIDA\n");
	return (0);
}


// && raw->map[ft_strlen(raw->map[j] - 1)][j] != '1'
