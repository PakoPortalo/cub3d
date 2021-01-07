/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:33:18 by fportalo          #+#    #+#             */
/*   Updated: 2021/01/07 12:56:02 by fportalo         ###   ########.fr       */
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

int		verLine(t_raycast *rc, t_data *img, int x)
{
	int		y;

	y = 0;
	while (y < img->map.h)
	{
		if(y < rc->drawStart)
			my_mlx_pixel_put(img, x, y, 0x00FF0000); // rojo
		if (y > rc->drawStart && y < rc->drawEnd)
			my_mlx_pixel_put(img, x, y, 0xFF5733); // naranja
		if (y > rc->drawEnd)
			my_mlx_pixel_put(img, x, y, 0x33FF5E ); //verde 
		y++;
	}
	return (0);
}

int		raycast_maths(t_data *img)
{
	t_raycast rc;
	int i;
	int x;
	int y;
	
	i = 1;
	x = 0;
	y = 0;
	img->img = mlx_new_image(img->ptr, img->map.h, img->map.w);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
	mlx_hook(img->win, 2, 1L<<0, funky_func_keypress, &img);
	mlx_hook(img->win, 17, 1L<<17, exit_win, &img);
	while(x < img->map.w) // Mientras que la X sea menor que el Width de la resolución
	{
		//Con esto calculamos la posición y dirección del rayo
		rc.cameraX = 2 * x / img->map.w - 1;
		rc.rayDirX = rc.dirX + rc.planeX * rc.cameraX;
		rc.rayDirY = rc.dirY + rc.planeY * rc.cameraX;
	


		rc.mapX = (int)rc.posX;
		rc.mapY = (int)rc.posY;
	
		rc.deltaDistX = (rc.rayDirY == 0) ? 0 : ((rc.rayDirX == 0) ? 1 : fabs(1 / rc.rayDirX));
		rc.deltaDistY = (rc.rayDirX == 0) ? 0 : ((rc.rayDirY == 0) ? 1 : fabs(1 / rc.rayDirY));
	

		// Con esto calculamos las coordenadas de la nueva posición
		if (rc.rayDirX < 0)
		{
			rc.stepX = -1;
			rc.sideDistX = (rc.posX - rc.mapX) * rc.deltaDistX; 
		}
		else
		{
			rc.stepX = 1;
			rc.sideDistX = (rc.mapX + 1.0 - rc.posX) * rc.deltaDistX;
		}
		if(rc.rayDirY < 0)
		{
			rc.stepY = -1;
			rc.sideDistY = (rc.posY - rc.mapY) * rc.deltaDistY;
		}
		else
		{
			rc.stepY = 1;
			rc.sideDistY = (rc.mapY + 1.0 - rc.posY) * rc.deltaDistY;
		}

		//Con esto aplicamos las coordenadas recogidas en los anteriores if/else
		//En el caso de que hit = 0, es decir, que no está chocando contra una pared
		while (rc.hit == 0)
		{
		if(rc.sideDistX < rc.sideDistY)
		{
			rc.sideDistX += rc.deltaDistX;
			rc.mapX += rc.stepX;
			rc.side = 0;
		}
		else
		{
			rc.sideDistY += rc.deltaDistY;
			rc.mapY += rc.stepY;
			rc.side = 1;
		}
		//Aquí determinamos la colisión contra una pared o no. Si mi mapa no tiene un 0 dentro, entonces tiene pared
		if(img->map.map[rc.mapX][rc.mapY] > 0)
			rc.hit = 1;
		x++;
	}
	//Calcula la distancia proyectada en la cámara
	if(rc.side == 0)
		rc.perpWallDist = (rc.mapX - rc.posX + (1 - rc.stepX) / 2) / rc.rayDirX;
	else
		rc.perpWallDist = (rc.mapY - rc.posY + (1 - rc.stepY) / 2) / rc.rayDirY;
	
	//lo del h = 10 me lo he inventado porque en el tuto pone una 'h' que no tengo ni idea de donde declara
	//Calculas la altura de la linea a dibujar en la pantalla
	rc.lineHeight = (int)(img->map.h / rc.perpWallDist);
	rc.drawStart = -(rc.lineHeight / 2) + (img->map.h / 2);
	
	//Calculas el mayor y el menor pixel para rellenar del mismo color en la línea en la que te encuentras 
	if(rc.drawStart < 0)
		rc.drawStart = 0;
	if(rc.drawEnd >= img->map.h)
		rc.drawEnd = img->map.h - 1;
	
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
	verLine(&rc, img, x);
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

	mlx_put_image_to_window(img->ptr, img->win, img->img, 0, 0);
	mlx_destroy_image(img->ptr, img->img);
	x++;
	return(0);
}