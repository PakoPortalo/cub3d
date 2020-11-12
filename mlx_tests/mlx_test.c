/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 10:32:22 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/12 12:37:13 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char		*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int				main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int x = 0;
	int y = 0;
	int z = 0;  //gradient

	float newx;
	float nexy;
	float angle = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "EL PEPE");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

/* Gradient
	while (x != 1920)
	{
		y = 0;
		if ((x % 2) == 1)
			z = 0;
		else
			z = 1;
		while (y != 1080)
		{
			if ((z % 2) == 1)
				my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			else
				my_mlx_pixel_put(&img, x, y, 0xFFFF00);
			z++;
			y++;
		}
		x++;
	}
*/
/* Square
	x = 1920/2 - 250;
	y = 1080/2 - 250;

	while (x < (1920/2 + 250))
	{
		y = 1080/2 - 250;
		while (y < 1080/2 + 250)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			y++;
		}
		x++;
	}
*/
/* Triangle
	x = 1920/2;
	y = 1080/2 - 200;
	z = 1;

	while (y != 1080/2)
	{
		x = 1920/2 - (z / 2);
		while (x < (1920/2) + (z / 2) + 1)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		y++;
		z = z + 2 ;
	}
*/

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
