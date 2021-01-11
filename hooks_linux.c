/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_linux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamagotchi <tamagotchi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:01:06 by tamagotchi        #+#    #+#             */
/*   Updated: 2021/01/11 10:07:39 by tamagotchi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			funky_func_keypress(int keycode)
{
	if (keycode == 65361)
		printf("keycode pressed is: Arrow Left\n");
	if (keycode == 65362)
		printf("keycode pressed is: Arrow Up\n");
	if (keycode == 65363)
		printf("keycode pressed is: Arrow Right\n");
	if (keycode == 65364)
		printf("keycode pressed is: Arrow Down\n");
	if (keycode == 65307)
	{
		printf("keycode pressed is: Esc\n");

		// mlx_destroy_image(img.ptr, img.img);
		// mlx_destroy_window(img.ptr, img.win);
		// free (img.img);
		// free (img.ptr);
		exit(0);
	}
	return(1);
}


// int		exit_win(int keycode)
// {
// 	keycode = 0;
// 	printf("Chao Pescao'\n");
// 	if (1L<<17)
// 		exit(0);
// 	return(0);
// }
