/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:33:18 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/18 17:15:34 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player_updown(t_raycast *rc, double move_x, double move_y)
{
	if (rc->keys.up == 1)
	{
		if (rc->map.map[(int)(rc->pos_x + move_x)][(int)(rc->pos_y)] == '3')
			rc->pos_x += move_x;
		if (rc->map.map[(int)(rc->pos_x)][(int)(rc->pos_y + move_y)] == '3')
			rc->pos_y += move_y;
	}
	if (rc->keys.down == 1)
	{
		if (rc->map.map[(int)(rc->pos_x - move_x)][(int)(rc->pos_y)] == '3')
			rc->pos_x -= move_x;
		if (rc->map.map[(int)(rc->pos_x)][(int)(rc->pos_y - move_y)] == '3')
			rc->pos_y -= move_y;
	}
}

void	move_player_leftright(t_raycast *rc, double move_x, double move_y)
{
	if (rc->keys.left == 1)
	{
		if (rc->map.map[(int)(rc->pos_x)][(int)(rc->pos_y + move_x)] == '3')
			rc->pos_y += move_x;
		if (rc->map.map[(int)(rc->pos_x - move_y)][(int)(rc->pos_y)] == '3')
			rc->pos_x -= move_y;
	}
	if (rc->keys.right == 1)
	{
		if (rc->map.map[(int)(rc->pos_x)][(int)(rc->pos_y - move_x)] == '3')
			rc->pos_y -= move_x;
		if (rc->map.map[(int)(rc->pos_x + move_y)][(int)(rc->pos_y)] == '3')
			rc->pos_x += move_y;
	}
}

void	rotate_player(t_raycast *rc)
{
	rc->old_dir_x = rc->dir_x;
	if (rc->keys.rot_right == 1)
	{
		rc->dir_x = rc->dir_x * cos(-rc->rot_speed) \
		- rc->dir_y * sin(-rc->rot_speed);
		rc->dir_y = rc->old_dir_x * sin(-rc->rot_speed) \
		+ rc->dir_y * cos(-rc->rot_speed);
		rc->old_plane_x = rc->plane_x;
		rc->plane_x = rc->plane_x * cos(-rc->rot_speed) \
		- rc->plane_y * sin(-rc->rot_speed);
		rc->plane_y = rc->old_plane_x * sin(-rc->rot_speed) \
		+ rc->plane_y * cos(-rc->rot_speed);
	}
	if (rc->keys.rot_left == 1)
	{
		rc->dir_x = rc->dir_x * cos(rc->rot_speed) \
		- rc->dir_y * sin(rc->rot_speed);
		rc->dir_y = rc->old_dir_x * sin(rc->rot_speed) \
		+ rc->dir_y * cos(rc->rot_speed);
		rc->old_plane_x = rc->plane_x;
		rc->plane_x = rc->plane_x * cos(rc->rot_speed) \
		- rc->plane_y * sin(rc->rot_speed);
		rc->plane_y = rc->old_plane_x * sin(rc->rot_speed) \
		+ rc->plane_y * cos(rc->rot_speed);
	}
}

void	player_movement(t_raycast *rc)
{
	double move_x;
	double move_y;

	move_x = rc->dir_x * rc->move_speed;
	move_y = rc->dir_y * rc->move_speed;
	move_player_updown(rc, move_x, move_y);
	move_player_leftright(rc, move_x, move_y);
	rotate_player(rc);
}

int		raycast_maths(t_raycast *rc)
{
	int x;

	x = 0;
	rc->img.img = mlx_new_image(rc->img.ptr, rc->map.w, rc->map.h);
	rc->img.addr = mlx_get_data_addr(rc->img.img, &rc->img.bits_per_pixel, \
	&rc->img.line_length, &rc->img.endian);
	while (x < rc->map.w)
	{
		rc->map_x = (int)rc->pos_x;
		rc->map_y = (int)rc->pos_y;
		ft_raydir(rc, x);
		ft_deltadist(rc);
		ft_sidedist(rc);
		ft_rayhit(rc);
		ft_walldist(rc);
		rc->z_buffer[x] = rc->perp_wall_dist;
		ft_buffer(rc, x);
		x++;
	}
	if (rc->map.sprite_count)
		ft_sprites(rc);
	if (rc->map.savecheck == 1)
	{
		screenshot(rc);
		exit(0);
	}
	mlx_put_image_to_window(rc->img.ptr, rc->img.win, rc->img.img, 0, 0);
	mlx_destroy_image(rc->img.ptr, rc->img.img);
	player_movement(rc);
	return (1);
}
