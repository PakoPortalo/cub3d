/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_calcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:42:31 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/17 17:42:48 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_raydir(t_raycast *rc, int x)
{
		rc->cameraX = 2 * x / (double)rc->map.w - 1;
		rc->rayDirX = rc->dirX + rc->planeX * rc->cameraX;
		rc->rayDirY = rc->dirY + rc->planeY * rc->cameraX;
}

void	ft_deltadist(t_raycast *rc)
{
	if (rc->rayDirX == 0)
	{
		rc->deltaDistX = 1;
		rc->deltaDistY = 0;
	}
	else if (rc->rayDirY == 0)
	{
		rc->deltaDistX = 0;
		rc->deltaDistY = 1;
	}
	else
	{
		rc->deltaDistX = fabs(1 / rc->rayDirX);
		rc->deltaDistY = fabs(1 / rc->rayDirY);
	}
}

void	ft_sidedist(t_raycast *rc)
{
	rc->hit = 0;
	if (rc->rayDirX < 0)
	{
		rc->stepX = -1;
		rc->sideDistX = (rc->posX - rc->mapX) * rc->deltaDistX;
	}
	else
	{
		rc->stepX = 1;
		rc->sideDistX = (rc->mapX + 1.0 - rc->posX) * rc->deltaDistX;
	}
	if(rc->rayDirY < 0)
	{
		rc->stepY = -1;
		rc->sideDistY = (rc->posY - rc->mapY) * rc->deltaDistY;
	}
	else
	{
		rc->stepY = 1;
		rc->sideDistY = (rc->mapY + 1.0 - rc->posY) * rc->deltaDistY;
	}
}

void	ft_rayhit(t_raycast *rc)
{
	while (rc->hit == 0)
	{
		if(rc->sideDistX < rc->sideDistY)
		{
			rc->sideDistX += rc->deltaDistX;
			rc->mapX += rc->stepX;
			rc->side = 0;
		}
		else
		{
			rc->sideDistY += rc->deltaDistY;
			rc->mapY += rc->stepY;
			rc->side = 1;
		}
		if(rc->map.map[rc->mapX][rc->mapY] == '1')
			rc->hit = 1;
	}
}

void	ft_walldist(t_raycast *rc)
{
	if(rc->side == 0)
		rc->perpWallDist = (rc->mapX - rc->posX + (1 - rc->stepX) / 2) / rc->rayDirX;
	else
		rc->perpWallDist = (rc->mapY - rc->posY + (1 - rc->stepY) / 2) / rc->rayDirY;
	rc->lineHeight = (int)(rc->map.h / rc->perpWallDist);
}
