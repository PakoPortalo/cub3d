/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:59:41 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/18 17:23:13 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		funky_func_keypress(int keycode, t_raycast *rc)
{
	if (keycode == 0)
		rc->keys.left = 1;
	if (keycode == 13)
		rc->keys.up = 1;
	if (keycode == 2)
		rc->keys.right = 1;
	if (keycode == 1)
		rc->keys.down = 1;
	if (keycode == 123)
		rc->keys.rot_left = 1;
	if (keycode == 124)
		rc->keys.rot_right = 1;
	if (keycode == 53)
		exit(0);
	return (1);
}

int		funky_func_keyrelease(int keycode, t_raycast *rc)
{
	if (keycode == 0)
		rc->keys.left = 0;
	if (keycode == 13)
		rc->keys.up = 0;
	if (keycode == 2)
		rc->keys.right = 0;
	if (keycode == 1)
		rc->keys.down = 0;
	if (keycode == 123)
		rc->keys.rot_left = 0;
	if (keycode == 124)
		rc->keys.rot_right = 0;
	return (1);
}

int		exit_win(int keycode)
{
	keycode = 0;
	if (1L << 17)
		exit(0);
	return (0);
}
