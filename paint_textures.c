/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:36:53 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/18 17:20:38 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		buffer_line(t_raycast *rc, t_tex_img *tex, int x, int line_height)
{
	int			i;
	double		step;
	double		tex_pos;

	i = 0;
	step = 1.0 * tex->height / line_height;
	tex_pos = (rc->draw_start - rc->map.h / 2 + line_height / 2) * step;
	while (i < rc->map.h)
	{
		if (i < rc->draw_start)
			my_mlx_pixel_put(&rc->img, x, i, rgb_to_hex(0, \
				rc->map.ceil[0], rc->map.ceil[1], rc->map.ceil[2]));
		else if (i >= rc->draw_end)
			my_mlx_pixel_put(&rc->img, x, i, rgb_to_hex(0, \
				rc->map.floor[0], rc->map.floor[1], rc->map.floor[2]));
		else if (i > rc->draw_start && i < rc->draw_end)
		{
			if ((rc->tex_y = (int)tex_pos) < 0)
				rc->tex_y = 0;
			tex_pos += step;
			my_mlx_pixel_put(&rc->img, x, i, \
				get_pixel(&tex->img, rc->tex_x, rc->tex_y));
		}
		i++;
	}
}

void		get_wall_texture(t_raycast *rc, t_tex_img **texture)
{
	if (rc->side == 0)
	{
		if (rc->step_x < 0)
			*texture = &rc->tex.textures[1];
		else
			*texture = &rc->tex.textures[0];
	}
	else
	{
		if (rc->step_y > 0)
			*texture = &rc->tex.textures[3];
		else
			*texture = &rc->tex.textures[2];
	}
}

void		ft_buffer(t_raycast *rc, int x)
{
	int			line_height;
	t_tex_img	*texture;

	texture = NULL;
	line_height = (int)(rc->map.h / rc->perp_wall_dist);
	rc->draw_start = -line_height / 2 + rc->map.h / 2;
	if (rc->draw_start < 0)
		rc->draw_start = 0;
	rc->draw_end = line_height / 2 + rc->map.h / 2;
	if (rc->draw_end >= rc->map.h)
		rc->draw_end = rc->map.h - 1;
	get_wall_texture(rc, &texture);
	if (rc->side == 0)
		rc->wall_x = rc->pos_y + rc->perp_wall_dist * rc->ray_dir_y;
	else
		rc->wall_x = rc->pos_x + rc->perp_wall_dist * rc->ray_dir_x;
	rc->wall_x -= floor(rc->wall_x);
	rc->tex_x = texture->width - (int)(rc->wall_x * (double)texture->width) - 1;
	if (rc->side == 0 && rc->ray_dir_x > 0)
		rc->tex_x = texture->width - rc->tex_x - 1;
	if (rc->side == 1 && rc->ray_dir_y < 0)
		rc->tex_x = texture->width - rc->tex_x - 1;
	buffer_line(rc, texture, x, line_height);
}
