/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamagotchi <tamagotchi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:33:18 by fportalo          #+#    #+#             */
/*   Updated: 2021/01/11 13:01:07 by tamagotchi       ###   ########.fr       */
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
		if(y < rc->drawStart)
			my_mlx_pixel_put(&rc->img, x, y, 0x111d5e); // azul
		else if (y > rc->drawStart && y < rc->drawEnd)
			my_mlx_pixel_put(&rc->img, x, y, 0xf37121); // naranja
		else if (y > rc->drawEnd)
			my_mlx_pixel_put(&rc->img, x, y, 0xc0e218 ); //verde 
		y++;
	}
	return (0);
}

int		raycast_maths(t_raycast *rc)
{
	int x;
	
	x = 0;
	rc->img.img = mlx_new_image(rc->img.ptr, rc->map.h, rc->map.w);
	rc->img.addr = mlx_get_data_addr(rc->img.img, &rc->img.bits_per_pixel, &rc->img.line_length,
								&rc->img.endian);
	while(x < rc->map.w) // Mientras que la X sea menor que el Width de la resolución
	{
		//Con esto calculamos la posición y dirección del rayo
		rc->cameraX = 2 * x / rc->map.w - 1;
		rc->rayDirX = rc->dirX + rc->planeX * rc->cameraX;
		rc->rayDirY = rc->dirY + rc->planeY * rc->cameraX;
	
		rc->mapX = (int)rc->posX;
		rc->mapY = (int)rc->posY;
		
		rc->hit = 0;


		rc->deltaDistX = (rc->rayDirY == 0) ? 0 : ((rc->rayDirX == 0) ? 1 : fabs(1 / rc->rayDirX));
		rc->deltaDistY = (rc->rayDirX == 0) ? 0 : ((rc->rayDirY == 0) ? 1 : fabs(1 / rc->rayDirY));
	

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
		rc->drawStart = -rc->lineHeight / 2 + rc->map.h / 2;
		if(rc->drawStart < 0)
			rc->drawStart = 0;
		rc->drawEnd = rc->lineHeight / 2 + rc->map.h / 2;
		if(rc->drawEnd >= rc->map.h)
			rc->drawEnd = rc->map.h - 1;

		// Esto no sé muy bien wtf nosequé. Lo que tengo seguro es que es para elegir los colores

		//choose wall color
		// ColorRGB color;
		// switch(worldMap[mapX][mapY])
		// {
		// case 1:  color = RGB_Red;    break; //red
		// case 2:  color = RGB_Green;  break; //green
		// case 3:  color = RGB_Blue;   break; //blue
		// case 4:  color = RGB_White;  break; //white
		// default: color = RGB_Yellow; break; //yellow
		// }

		//Esto tampoco sé muy bien para qué es, se supone que sirve para dibujar la linea
		//pero utiliza una función externa que a saber cual es
		//      verLine(x, drawStart, drawEnd, color);
		verLine(rc, x);
		x++;
	}
		//Ahora habla de cosas relacionadas con los fps que la verdad si que me gustaría
		//implementar en el código sobre todo para el debuggeo, pero lo voy a dejar por ahora

	// Lo que viene ahora no es muy difícil, es lo de los hooks y las teclas, pero habría que plantearlo 
	// Diferente. Creo que esto no lo voy a hacer hasta que no se me vea el mapa en pantalla
	
	// if(keyDown(SDLK_UP))
	// {
	// 	if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
	// 	if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
	// }
	// //move backwards if no wall behind you
	// if(keyDown(SDLK_DOWN))
	// {
	// 	if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
	// 	if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
	// }
	// //rotate to the right
	// if(keyDown(SDLK_RIGHT))
	// {
	// 	//both camera direction and camera plane must be rotated
	// 	double oldDirX = dirX;
	// 	dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
	// 	dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
	// 	double oldPlaneX = planeX;
	// 	planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
	// 	planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	// }
	// //rotate to the left
	// if(keyDown(SDLK_LEFT))
	// {
	// 	//both camera direction and camera plane must be rotated
	// 	double oldDirX = dirX;
	// 	dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
	// 	dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
	// 	double oldPlaneX = planeX;
	// 	planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
	// 	planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);

	mlx_put_image_to_window(rc->img.ptr, rc->img.win, rc->img.img, 0, 0);
	mlx_destroy_image(rc->img.ptr, rc->img.img);
	return(0);
}
