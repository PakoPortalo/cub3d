/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:27:27 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/17 19:30:13 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(t_data *img, t_tex_img *texture, char *path)
{
	texture->img.img = mlx_xpm_file_to_image(img->ptr, path, \
											&texture->width, &texture->height);
	texture->img.addr = mlx_get_data_addr(texture->img.img, \
	&texture->img.bits_per_pixel, &texture->img.line_length, \
	&texture->img.endian);
}

void	load_all_textures(t_raycast *rc)
{
	load_texture(&rc->img, &rc->tex.textures[0], rc->map.north);
	load_texture(&rc->img, &rc->tex.textures[1], rc->map.south);
	load_texture(&rc->img, &rc->tex.textures[2], rc->map.east);
	load_texture(&rc->img, &rc->tex.textures[3], rc->map.west);
	load_texture(&rc->img, &rc->tex.textures[4], rc->map.sprite);
}
