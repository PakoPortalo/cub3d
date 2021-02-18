/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_calcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:42:31 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/18 17:17:43 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_raydir(t_raycast *rc, int x)
{
	rc->camera_x = 2 * x / (double)rc->map.w - 1;
	rc->ray_dir_x = rc->dir_x + rc->plane_x * rc->camera_x;
	rc->ray_dir_y = rc->dir_y + rc->plane_y * rc->camera_x;
}

void	ft_deltadist(t_raycast *rc)
{
	if (rc->ray_dir_x == 0)
	{
		rc->delta_dist_x = 1;
		rc->delta_dist_y = 0;
	}
	else if (rc->ray_dir_y == 0)
	{
		rc->delta_dist_x = 0;
		rc->delta_dist_y = 1;
	}
	else
	{
		rc->delta_dist_x = fabs(1 / rc->ray_dir_x);
		rc->delta_dist_y = fabs(1 / rc->ray_dir_y);
	}
}

void	ft_sidedist(t_raycast *rc)
{
	rc->hit = 0;
	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (rc->pos_x - rc->map_x) * rc->delta_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = (rc->map_x + 1.0 - rc->pos_x) * rc->delta_dist_x;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (rc->pos_y - rc->map_y) * rc->delta_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0 - rc->pos_y) * rc->delta_dist_y;
	}
}

void	ft_rayhit(t_raycast *rc)
{
	while (rc->hit == 0)
	{
		if (rc->side_dist_x < rc->side_dist_y)
		{
			rc->side_dist_x += rc->delta_dist_x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->side_dist_y += rc->delta_dist_y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		if (rc->map.map[rc->map_x][rc->map_y] == '1')
			rc->hit = 1;
	}
}

void	ft_walldist(t_raycast *rc)
{
	if (rc->side == 0)
		rc->perp_wall_dist = (rc->map_x - rc->pos_x + \
		(1 - rc->step_x) / 2) / rc->ray_dir_x;
	else
		rc->perp_wall_dist = (rc->map_y - rc->pos_y + \
		(1 - rc->step_y) / 2) / rc->ray_dir_y;
	rc->line_height = (int)(rc->map.h / rc->perp_wall_dist);
}
