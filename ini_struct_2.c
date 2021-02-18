/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_struct_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:32:38 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/18 17:16:48 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	iniraycast_1(t_raycast *rc)
{
	rc->pos_x = 0;
	rc->pos_y = 0;
	rc->dir_x = 0;
	rc->dir_y = 0;
	rc->plane_x = 0;
	rc->plane_y = 0;
	rc->camera_x = 0;
	rc->ray_dir_x = 0;
	rc->ray_dir_y = 0;
	rc->map_x = 0;
	rc->map_y = 0;
	rc->side_dist_x = 0;
	rc->side_dist_y = 0;
	rc->delta_dist_x = 0;
	rc->delta_dist_y = 0;
	rc->perp_wall_dist = 0;
}

void	iniraycast_2(t_raycast *rc)
{
	rc->step_x = 0;
	rc->step_y = 0;
	rc->hit = 0;
	rc->side = 0;
	rc->line_height = 0;
	rc->draw_start = 0;
	rc->draw_end = 0;
	rc->move_speed = 0.08;
	rc->rot_speed = 0.08;
	rc->old_dir_x = 0;
	rc->old_plane_x = 0;
	rc->tex_num = 0;
	rc->wall_x = 0;
	rc->tex_x = 0;
	rc->tex_y = 0;
}
