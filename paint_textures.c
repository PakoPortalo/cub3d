/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:36:53 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/17 18:49:03 by fportalo         ###   ########.fr       */
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
	tex_pos = (rc->drawStart - rc->map.h / 2 + line_height / 2) * step;
	while (i < rc->map.h)
	{
		if (i < rc->drawStart)
			my_mlx_pixel_put(&rc->img, x, i, \
				rgb_to_hex(0, rc->map.ceil[0], \
				rc->map.ceil[1], rc->map.ceil[2]));
		else if (i >= rc->drawEnd)
			my_mlx_pixel_put(&rc->img, x, i, \
				rgb_to_hex(0, rc->map.floor[0], \
				rc->map.floor[1], rc->map.floor[2]));
		else if (i > rc->drawStart && i < rc->drawEnd)
		{
			if ((rc->texY = (int)tex_pos) < 0)
				rc->texY = 0;
			tex_pos += step;
			my_mlx_pixel_put(&rc->img, x, i, \
				get_pixel(&tex->img, rc->texX, rc->texY));
		}
		i++;
	}
}

// void		get_wall_texture(t_raycast *rc, t_tex_img *texture)
// {
// 	if (rc->side == 0)
// 	{
// 		if (rc->stepX < 0)
// 			texture = &rc->tex.textures[0];
// 		else
// 			texture = &rc->tex.textures[1];
// 	}
// 	else
// 	{
// 		if (rc->stepY > 0)
// 			texture = &rc->tex.textures[2];
// 		else
// 			texture = &rc->tex.textures[3];
// 	}
// }

void		ft_buffer(t_raycast *rc, int x)
{
	int			line_height;
	t_tex_img	*texture;

	texture = NULL;
	line_height = (int)(rc->map.h / rc->perpWallDist);
	rc->drawStart = -line_height / 2 + rc->map.h / 2;
	if (rc->drawStart < 0)
		rc->drawStart = 0;
	rc->drawEnd = line_height / 2 + rc->map.h / 2;
	if (rc->drawEnd >= rc->map.h)
		rc->drawEnd = rc->map.h - 1;
	// get_wall_texture(rc, &texture);
	if (rc->side == 0)
	{
		if (rc->stepX < 0)
			texture = &rc->tex.textures[0];
		else
			texture = &rc->tex.textures[1];
	}
	else
	{
		if (rc->stepY > 0)
			texture = &rc->tex.textures[2];
		else
			texture = &rc->tex.textures[3];
	}
	if (rc->side == 0)
		rc->wallX = rc->posY + rc->perpWallDist * rc->rayDirY;
	else
		rc->wallX = rc->posX + rc->perpWallDist * rc->rayDirX;
	rc->wallX -= floor(rc->wallX);
	rc->texX = texture->width - (int)(rc->wallX * (double)texture->width) - 1;
	if (rc->side == 0 && rc->rayDirX > 0)
		rc->texX = texture->width - rc->texX - 1;
	if (rc->side == 1 && rc->rayDirY < 0)
		rc->texX = texture->width - rc->texX - 1;
	buffer_line(rc, texture, x, line_height);
}
