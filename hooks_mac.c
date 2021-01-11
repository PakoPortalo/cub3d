/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamagotchi <tamagotchi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:59:41 by fportalo          #+#    #+#             */
/*   Updated: 2021/01/10 19:37:02 by tamagotchi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				funky_func_keypress(int keycode)
{
	if (keycode == 53)
	{
		printf("keycode pressed is: ESC\n");
		// mlx_destroy_image(img.ptr, img.img);
		// mlx_destroy_window(img.ptr, img.win);
		// free (img.img);
		// free (img.ptr);
		exit(0);
	}
	if (keycode == 123)
		printf("keycode pressed is: Arrow Left\n");
	if (keycode == 126)
		printf("keycode pressed is: Arrow Up\n");
	if (keycode == 124)
		printf("keycode pressed is: Arrow Right\n");
	if (keycode == 125)
		printf("keycode pressed is: Arrow Down\n");
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
