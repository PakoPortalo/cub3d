/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_linux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamagotchi <tamagotchi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:01:06 by tamagotchi        #+#    #+#             */
/*   Updated: 2021/01/15 11:42:08 by tamagotchi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			funky_func_keypress(int keycode, t_raycast *rc)
{
	printf("keycode pressed is: %d\n", keycode);

	if (keycode == 97)
	{
		rc->keys.left = 1;
		printf("keycode pressed is: Arrow Left\n");
	}
	if (keycode == 119)
	{
		rc->keys.up = 1;
		printf("keycode pressed is: Arrow Up\n");
	}
	if (keycode == 100)
	{
		rc->keys.right = 1;
		printf("keycode pressed is: Arrow Right\n");
	}
	if (keycode == 115)
	{
		rc->keys.down = 1;
		printf("keycode pressed is: Arrow Down\n");
	}
	if (keycode == 65361)
	{
		rc->keys.rotLeft = 1;
		printf("keycode pressed is: Arrow Down\n");
	}
		if (keycode == 65363)
	{
		rc->keys.rotRight = 1;
		printf("keycode pressed is: Arrow Down\n");
	}
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

int			funky_func_keyrelease(int keycode, t_raycast *rc)
{
	if (keycode == 97)
	{
		rc->keys.left = 0;
		printf("keycode released is: Arrow Left\n");
	}
	if (keycode == 119)
	{
		rc->keys.up = 0;
		printf("keycode released is: Arrow Up\n");
	}
	if (keycode == 100)
	{
		rc->keys.right = 0;
		printf("keycode released is: Arrow Right\n");
	}
	if (keycode == 115)
	{
		rc->keys.down = 0;
		printf("keycode released is: Arrow Down\n");
	}
	if (keycode == 65361)
	{
		rc->keys.rotLeft = 0;
		printf("keycode released is: Rotate Left\n");
	}
	if (keycode == 65363)
	{
		rc->keys.rotRight = 0;
		printf("keycode released is: Rotate Right\n");
	}
	return(1);
}

int		exit_win(int keycode)
{
	(void)keycode;
	printf("Chao Pescao'\n");
	if (1L<<17)
		exit(0);
	return(0);
}
