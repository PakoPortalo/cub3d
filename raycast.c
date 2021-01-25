/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:33:18 by fportalo          #+#    #+#             */
/*   Updated: 2021/01/25 12:44:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*

	posX, poxY. Posiciones para empezar. Yo uso map->x, map->y
	dirX, dirY. Pongo las que vienen en raycaster_flt.cpp pero imagino que dependerá de NSWE
	planeX, planeY. Camera plane, lo que se ve
	cameraX representa la coordenada X del plano de cámara,yendo de -1 (borde izquierda)
			hasta 1 (borde derecha), siendo el centro de la pantalla el 0

	mapX, mapY	son las coordenaadas del cuadrado, son int para que solo contengan
				los bordes
	deltaDistX, deltaDistY son las distancias en donde corta con los ejes x e y respectivamente

*/

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		verLine(t_raycast *rc, int x)
{
	int		y;

	y = 0;
	while (y < rc->map.h)
	{
		if(y <= rc->drawStart)
			my_mlx_pixel_put(&rc->img, x, y, 0x7effdb); // techo amarillo
		else if (y > rc->drawStart && y < rc->drawEnd)
		{
			if (rc->side == 0)
				my_mlx_pixel_put(&rc->img, x, y, 0xb693fe); // muro verde
			else if (rc->side == 1)
				my_mlx_pixel_put(&rc->img, x, y, 0x8c82fc); // muro verde oscuro
		}
		else if (y >= rc->drawEnd)
			my_mlx_pixel_put(&rc->img, x, y, 0xff9de2 ); // suelo marron

		y++;
	}
	return (0);
}

int		move_player(t_raycast *rc, double moveX, double moveY)
{
	if(rc->keys.up == 1)
	{
		if(rc->map.map[(int)(rc->posY)][(int)(rc->posX + moveX)] != '1')
			rc->posX += moveX;
		if(rc->map.map[(int)(rc->posY + moveY)][(int)(rc->posX)] != '1')
			rc->posY += moveY;
	}
	if(rc->keys.down == 1)
	{
		if(rc->map.map[(int)(rc->posY)][(int)(rc->posX - moveX)] != '1')
			rc->posX -= moveX;
		if(rc->map.map[(int)(rc->posY - moveY)][(int)(rc->posX)] != '1')
			rc->posY -= moveY;
	}
	if(rc->keys.right == 1)
	{
		if(rc->map.map[(int)(rc->posY)][(int)(rc->posX - moveY)] != '1')
			rc->posX -= moveY;
		if(rc->map.map[(int)(rc->posY + moveX)][(int)(rc->posX)] != '1')
			rc->posY += moveX;
	}
	if(rc->keys.left == 1)
	{
		if(rc->map.map[(int)(rc->posY)][(int)(rc->posX + moveY)] != '1')
			rc->posX += moveY;
		if(rc->map.map[(int)(rc->posY - moveX)][(int)(rc->posX)] != '1')
			rc->posY -= moveX;
	}
	return (1);
}

int		rotate_player(t_raycast *rc)
{
	if(rc->keys.rotLeft == 1)
	{
		//both camera direction and camera plane must be rotated
		rc->oldDirX = rc->dirX;
		rc->dirX = rc->dirX * cos(-rc->rotSpeed) - rc->dirY * sin(-rc->rotSpeed);
		rc->dirY = rc->oldDirX * sin(-rc->rotSpeed) + rc->dirY * cos(-rc->rotSpeed);

		rc->oldPlaneX = rc->planeX;
		rc->planeX = rc->planeX * cos(-rc->rotSpeed) - rc->planeY * sin(-rc->rotSpeed);
		rc->planeY = rc->oldPlaneX * sin(-rc->rotSpeed) + rc->planeY * cos(-rc->rotSpeed);
	}
	//rotate to the left
	if(rc->keys.rotRight == 1)
	{
		//both camera direction and camera plane must be rotated
		rc->oldDirX = rc->dirX;
		rc->dirX = rc->dirX * cos(rc->rotSpeed) - rc->dirY * sin(rc->rotSpeed);
		rc->dirY = rc->oldDirX * sin(rc->rotSpeed) + rc->dirY * cos(rc->rotSpeed);
		rc->oldPlaneX = rc->planeX;
		rc->planeX = rc->planeX * cos(rc->rotSpeed) - rc->planeY * sin(rc->rotSpeed);
		rc->planeY = rc->oldPlaneX * sin(rc->rotSpeed) + rc->planeY * cos(rc->rotSpeed);
	}
	return(1);
}

int		player_movement(t_raycast *rc)
{
	double moveX;
	double moveY;

	moveX = rc->dirX * rc->moveSpeed;
	moveY = rc->dirY * rc->moveSpeed;
	move_player(rc, moveX, moveY);
	rotate_player(rc);
	return(1);
}

int		raycast_maths(t_raycast *rc)
{
	int x;

	x = 0;
	rc->img.img = mlx_new_image(rc->img.ptr, rc->map.w, rc->map.h);
	rc->img.addr = mlx_get_data_addr(rc->img.img, &rc->img.bits_per_pixel, &rc->img.line_length,
								&rc->img.endian);
	while(x < rc->map.w) // Mientras que la X sea menor que el Width de la resolución
	{

		//Con esto calculamos la posición y dirección del rayo
		rc->cameraX = 2 * x / (double)rc->map.w - 1;

		rc->rayDirX = rc->dirX + rc->planeX * rc->cameraX;
		rc->rayDirY = rc->dirY + rc->planeY * rc->cameraX;

		rc->mapX = rc->posX;
		rc->mapY = rc->posY;

		rc->deltaDistX = (rc->rayDirY == 0) ? 0 : ((rc->rayDirX == 0) ? 1 : fabs(1 / rc->rayDirX));
		rc->deltaDistY = (rc->rayDirX == 0) ? 0 : ((rc->rayDirY == 0) ? 1 : fabs(1 / rc->rayDirY));

		rc->hit = 0;
		// Con esto calculamos las coordenadas de la nueva posición
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

		//Con esto aplicamos las coordenadas recogidas en los anteriores if/else
		//En el caso de que hit = 0, es decir, que no está chocando contra una pared
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
		//Aquí determinamos la colisión contra una pared o no. Si mi mapa no tiene un 0 dentro, entonces tiene pared
				if(rc->map.map[rc->mapY][rc->mapX] == '1')
					rc->hit = 1;
		}

		//Calcula la distancia proyectada en la cámara
		if(rc->side == 0) // si side == 0 está mirando arriba o abajo. Si side == 1 está mirando a izq o dcha
			rc->perpWallDist = (rc->mapX - rc->posX + (1 - rc->stepX) / 2) / rc->rayDirX;
		else
			rc->perpWallDist = (rc->mapY - rc->posY + (1 - rc->stepY) / 2) / rc->rayDirY;

		//Calculas la altura de la linea a dibujar en la pantalla
		rc->lineHeight = (int)(rc->map.h / rc->perpWallDist);

		//Calculas el mayor y el menor pixel para rellenar del mismo color en la línea en la que te encuentras
		rc->drawStart = -(rc->lineHeight) / 2 + rc->map.h / 2;
		if(rc->drawStart < 0)
			rc->drawStart = 0;

		rc->drawEnd = rc->lineHeight / 2 + rc->map.h / 2;
		if(rc->drawEnd >= rc->map.h)
			rc->drawEnd = rc->map.h - 1;


		// Dibuja muros con la información de draw start y draw end
 		verLine(rc, x);
		x++;
	}
	player_movement(rc);
	mlx_put_image_to_window(rc->img.ptr, rc->img.win, rc->img.img, 0, 0);
	mlx_destroy_image(rc->img.ptr, rc->img.img);
	return(0);
}
