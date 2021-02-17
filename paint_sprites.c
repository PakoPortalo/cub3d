/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:39:47 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/17 18:35:13 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_calc(t_raycast *rc, t_sprite *sprite, int i)
{
	sprite->x = rc->sprite[i].x - rc->posX + 0.5;
	sprite->y = rc->sprite[i].y - rc->posY + 0.5;
	sprite->inv_det = 1.0 / ((rc->planeX * rc->dirY) - (rc->dirX * rc->planeY));
	sprite->transform_x = sprite->inv_det * \
	((rc->dirY * sprite->x) - (rc->dirX * sprite->y));
	sprite->transform_y = sprite->inv_det * \
	((-rc->planeY * sprite->x) + (rc->planeX * sprite->y));
	sprite->screen_x = (int)((rc->map.w / 2) * \
	(1 + sprite->transform_x / sprite->transform_y));
	sprite->height = abs((int)(rc->map.h / sprite->transform_y));
	sprite->draw_start_y = (-sprite->height / 2) + (rc->map.h / 2);
	if (sprite->draw_start_y < 0)
		sprite->draw_start_y = 0;
	sprite->draw_end_y = (sprite->height / 2) + (rc->map.h / 2);
	if (sprite->draw_end_y >= rc->map.h)
		sprite->draw_end_y = rc->map.h - 1;
	sprite->width = abs((int)(rc->map.h / sprite->transform_y));
	sprite->draw_start_x = (-sprite->width / 2) + sprite->screen_x;
	if (sprite->draw_start_x < 0)
		sprite->draw_start_x = 0;
	sprite->draw_end_x = (sprite->width / 2) + sprite->screen_x;
	if (sprite->draw_end_x >= rc->map.w)
		sprite->draw_end_x = rc->map.w - 1;
}

void	stripe_put(t_raycast *rc, t_sprite *sprite, int x, t_tex_img *tex)
{
	int		d;
	int		y;
	int		color;

	y = 0;
	sprite->tex_x = (int)(256 * (x - (-sprite->width / 2 + sprite->screen_x)) \
	* tex->width / sprite->width) / 256;
	if (sprite->transform_y > 0 && x > 0 && x < rc->map.w && \
		sprite->transform_y < rc->zBuffer[x])
	{
		y = sprite->draw_start_y;
		while (y < sprite->draw_end_y)
		{
			d = y * 256 - (rc->map.h * 128) + (sprite->height * 128);
			sprite->tex_y = ((d * tex->height) / sprite->height) / 256;
			if (sprite->tex_y < 0)
				sprite->tex_y = 0;
			color = get_pixel(&tex->img, sprite->tex_x, sprite->tex_y);
			if ((color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(&rc->img, x, y, color);
			y++;
		}
	}
}

void	ft_sprites(t_raycast *rc)
{
	int			i;
	int			scount;
	t_sprite	sprite;
	t_tex_img	tex;

	i = 0;
	tex = rc->tex.textures[4];
	inisprite(&sprite);
	save_sprites(rc);
	while (i < rc->map.sprite_count)
	{
		sprite_calc(rc, &sprite, i);
		scount = sprite.draw_start_x;
		while (scount < sprite.draw_end_x)
		{
			stripe_put(rc, &sprite, scount, &tex);
			scount++;
		}
		i++;
	}
}
