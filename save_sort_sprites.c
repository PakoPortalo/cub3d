/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_sort_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:01:00 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/18 17:22:47 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		while (rc->map.map[i][j])
		{
			if (rc->map.map[i][j] == '4')
			{
				rc->sprite[sprite].x = i;
				rc->sprite[sprite].y = j;
				rc->sprite[sprite].perpdist = pow(rc->pos_x - i, 2.0) \
				+ pow(rc->pos_y - j, 2.0);
				sprite++;
			}
			j++;
		}
		i++;
	}
	sort_sprites(rc);
}
