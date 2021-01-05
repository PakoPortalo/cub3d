/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:31:12 by fportalo          #+#    #+#             */
/*   Updated: 2021/01/05 13:39:54 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		print_square(t_data *data, int color)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x != 100)
	{
		y = 0;
		while (y != 100)
		{
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
}
int		raycast_start(t_data *img)
{
	img->img = mlx_new_image(img->ptr, img->map.h, img->map.w);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
	print_square(img, 0x00FF0000);
	// raycast_maths(img);
	mlx_put_image_to_window(img->ptr, img->win, img->img, 0, 0);
	mlx_destroy_image(img->ptr, img->img);

	return(1);
}

int			printer_cub3d(mapclean *map)
{
	t_data	img;

	map_to_img(&img, map);
	img.ptr = mlx_init();
	img.win = mlx_new_window(img.ptr, map->w, map->h, "Hello world!");
	mlx_hook(img.win, 2, 1L<<0, funky_func_keypress, &img);
	mlx_hook(img.win, 17, 1L<<17, exit_win, &img);
	mlx_loop_hook(img.ptr, raycast_start, &img);
	mlx_loop(img.ptr);
	return (0);
}
