/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_struct_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:32:38 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/18 16:56:28 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	iniraycast_1(t_raycast *rc)
{
	rc->posX = 0;
	rc->posY = 0;
	rc->dirX = 0;
	rc->dirY = 0;
	rc->planeX = 0;
	rc->planeY = 0;
	rc->cameraX = 0;
	rc->rayDirX = 0;
	rc->rayDirY = 0;
	rc->mapX = 0;
	rc->mapY = 0;
	rc->sideDistX = 0;
	rc->sideDistY = 0;
	rc->deltaDistX = 0;
	rc->deltaDistY = 0;
	rc->perpWallDist = 0;
}

void	iniraycast_2(t_raycast *rc)
{
	rc->stepX = 0;
	rc->stepY = 0;
	rc->hit = 0;
	rc->side = 0;
	rc->lineHeight = 0;
	rc->drawStart = 0;
	rc->drawEnd = 0;
	rc->moveSpeed = 0.08;
	rc->rotSpeed = 0.08;
	rc->oldDirX = 0;
	rc->oldPlaneX = 0;
	rc->texNum = 0;
	rc->wallX = 0;
	rc->texX = 0;
	rc->texY = 0;
}
