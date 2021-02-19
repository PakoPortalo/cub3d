/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:38:58 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/19 12:40:48 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast_sprites_screenshot(t_raycast *rc)
{
	if (rc->map.sprite_count)
		ft_sprites(rc);
	if (rc->map.savecheck == 1)
	{
		screenshot(rc);
		exit(0);
	}
}
