/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:33:10 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/17 17:33:29 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		buffer_pixel(t_data *data, int x, int y, int color)
{
	*(int*)(data->addr + (y * data->line_length + x * \
			(data->bits_per_pixel / 8))) = color;
}

int			get_pixel(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

int			rgb_to_hex(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}