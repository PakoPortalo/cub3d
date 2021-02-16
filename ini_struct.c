/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 09:11:59 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/16 16:52:27 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		iniraw(mapstr *raw)
{
	raw->res = NULL;
	raw->north = NULL;
	raw->south = NULL;
	raw->west = NULL;
	raw->east = NULL;
	raw->sprite = NULL;
	raw->floor = NULL;
	raw->ceil = NULL;
	raw->map = NULL;
	raw->rows = 0;
	raw->varnum = 0;
	raw->x = 0;
	raw->y = 0;
	raw->sprite_count = 0;
}

void		inimap(mapclean *map)
{
	map->w = 0;
	map->h = 0;
	map->north = NULL;
	map->south = NULL;
	map->west = NULL;
	map->east = NULL;
	map->sprite = NULL;
	map->floor[0] = -1;
	map->floor[1] = -1;
	map->floor[2] = -1;
	map->ceil[0] = -1;
	map->ceil[1] = -1;
	map->ceil[2] = -1;
	map->map = NULL;
	map->x = 0;
	map->y = 0;
	map->orientation = '0';
	map->sprite_count = 0;
	map->rows = 0;
}

void		ininum(mapconfig *num)
{
	num->res = 0;
	num->north = 0;
	num->south = 0;
	num->west = 0;
	num->east = 0;
	num->sprite = 0;
	num->floor = 0;
	num->ceil = 0;
}

void		inisprite(t_sprite *s)
{
	s->x = 0;
	s->y = 0;
	s->inv_det = 0;
	s->transform_x = 0;
	s->transform_y = 0;
	s->screen_x = 0;
	s->screen_y = 0;
	s->height = 0;
	s->width = 0;
	s->draw_start_x = 0;
	s->draw_end_x = 0;
	s->draw_start_y = 0;
	s->draw_end_y = 0;
	s->tex_x = 0;
	s->tex_y = 0;
}
void		iniraycast(t_raycast *rc)
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
	rc->stepX = 0;
	rc->stepY = 0;
	rc->hit = 0;
	rc->side = 0;
	rc->lineHeight = 0;
	rc->drawStart = 0;
	rc->drawEnd = 0;
	// rc->frameTime = 0;
	rc->moveSpeed = 0.08;
	rc->rotSpeed = 0.08;
	rc->oldDirX = 0;
	rc->oldPlaneX = 0;
	
	rc->texNum = 0;
	rc->wallX = 0;
	rc->texX = 0;
	// rc->step = 0;
	// rc->texPos = 0;
	rc->texY = 0;


	// rc->width = 0;
	// rc->height = 0;
	// rc->zBuffer = 0;
}

void	inihandlekeys(t_handlekeys *keys)
{
	keys->left = 0;
	keys->up = 0;
	keys->right = 0;
	keys->down = 0;
	keys->rotLeft = 0;
	keys->rotRight = 0;
}

// void	inisprite(t_sprite *sprite)
// {
// 	sprite->x = 0;
// 	sprite->y = 0;
// 	sprite->xRel = 0;		//spriteX
// 	sprite->yRel = 0;		//spriteY
// 	sprite->invDet = 0;
// 	sprite->transformX = 0;
// 	sprite->transformY = 0;
// 	sprite->spriteScreenX = 0;
// 	sprite->spriteHeight = 0;
// 	sprite->drawStartY = 0;
// 	sprite->drawEndX = 0;
// 	sprite->width = 0;
// 	sprite->height = 0;
// 	sprite->perpdist = 0;
// }