/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:06:44 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/23 13:09:52 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_res(mapstr *raw)
{
	int i;

	i = 0;
	while (raw->res[i] != '\0')
	{
		if (!ft_strchr("R 0123456789", raw->res[i]))
		{
			printf("Resolution Error.\nPlease introduce a valid resolution");
			return (-1);
		}
		i++;
	}
	return (1);
}

int		save_map_info(mapstr *raw)
{
	if (check_res(raw) == -1)
		return (-1);
	return (1);
}
