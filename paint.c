/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:31:12 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/16 17:21:11 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(t_data *img, t_tex_img *texture, char *path)
{
	texture->img.img = mlx_xpm_file_to_image(img->ptr, path, \
											&texture->width, &texture->height);
	texture->img.addr = mlx_get_data_addr(texture->img.img, &texture->img.bits_per_pixel, \
							&texture->img.line_length, &texture->img.endian);
}

void	load_all_textures(t_raycast *rc)
{
	// tex->n_texture = rc->map.north;
	// tex->s_texture = rc->map.north;
	// tex->e_texture = rc->map.north;
	// tex->w_texture = rc->map.north;
	load_texture(&rc->img, &rc->tex.textures[0], rc->map.north);
	load_texture(&rc->img, &rc->tex.textures[1], rc->map.south);
	load_texture(&rc->img, &rc->tex.textures[2], rc->map.east);
	load_texture(&rc->img, &rc->tex.textures[3], rc->map.west);
	load_texture(&rc->img, &rc->tex.textures[4], rc->map.sprite);
}

void	orientation_input(double dirX, double dirY, double plX, double plY, t_raycast *rc)
{
	rc->dirX = dirX;
	rc->dirY = dirY;
	rc->planeX = plX;
	rc->planeY = plY;
}

void	swap_swap(t_sprite *ptr1, t_sprite *ptr2)
{
	t_sprite	aux;

	aux = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = aux;
}

void	sort_sprites(t_raycast *rc)
{
	int i;
	int j;

	i = 0;
	while (i < rc->map.sprite_count)
	{
		j = 0;
		while (j < rc->map.sprite_count - i - 1)
		{
			if (rc->sprite[j].perpdist < rc->sprite[j + 1].perpdist)
				swap_swap(rc->sprite + j, rc->sprite + j + 1);
			j++; 
		}
		i++;
	}
}

void	save_sprites(t_raycast *rc)
{
	int i;
	int j;
	int sprite;

	i = 0;
	sprite = 0;
	while (i < rc->map.rows && sprite < rc->map.sprite_count)
	{
		j = 0;
		while(rc->map.map[i][j])
		{
			if (rc->map.map[i][j] == '4')
			{
				rc->sprite[sprite].x = i;
				rc->sprite[sprite].y = j;
				rc->sprite[sprite].perpdist = pow(rc->posX - i, 2.0) + pow(rc->posY - j, 2.0);
				sprite++;
			}
			j++;
		}
		i++;
	}
	sort_sprites(rc);
}

int		raycast_start(t_raycast *rc)
{
	rc->posX = (double)rc->map.y + 0.5f;
	rc->posY = (double)rc->map.x + 0.5f;

	load_all_textures(rc);
	rc->zBuffer = malloc(sizeof(double) * rc->map.w);
	if (rc->map.orientation == 'N')
		orientation_input(-1, 0, 0, 0.66, rc);
	if (rc->map.orientation == 'S')
		orientation_input(1, 0, 0, -0.66, rc);
	if (rc->map.orientation == 'E')
		orientation_input(0, 1, 0.66, 0, rc);
	if (rc->map.orientation == 'W')
		orientation_input(0, -1, -0.66, 0, rc);
	if(rc->map.sprite_count > 0)
	{
		rc->sprite = (t_sprite *)malloc(sizeof(t_sprite) * rc->map.sprite_count);
		save_sprites(rc);
	}

	return(1);
}

int			printer_cub3d(mapclean *map)
{
	t_data	img;
	t_raycast rc;
	t_handlekeys keys;

	img.ptr = mlx_init();
	img.win = mlx_new_window(img.ptr, map->w, map->h, "Hello world!");

	rc.map = *map;
	rc.img = img;
	inihandlekeys(&keys);
	rc.keys = keys;
	iniraycast(&rc);
	raycast_start(&rc);
	mlx_hook(rc.img.win, 2, 1L << 0, funky_func_keypress, &rc);
	mlx_hook(rc.img.win, 3, 1L << 1, funky_func_keyrelease, &rc);
	mlx_hook(rc.img.win, 17, 1L<<17, exit_win, &rc.img);
	mlx_loop_hook(img.ptr, raycast_maths, &rc);
	mlx_loop(img.ptr);
	return (0);
}
