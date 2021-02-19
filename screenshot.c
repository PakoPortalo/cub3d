/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:04:33 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/19 12:40:14 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				create_header(t_raycast *rc, unsigned char *fileheader, \
					unsigned char *infoheader, int filesize)
{
	fileheader[0] = (unsigned char)'B';
	fileheader[1] = (unsigned char)'M';
	fileheader[2] = (unsigned char)(filesize);
	fileheader[3] = (unsigned char)(filesize >> 8);
	fileheader[4] = (unsigned char)(filesize >> 16);
	fileheader[5] = (unsigned char)(filesize >> 24);
	fileheader[10] = (unsigned char)(14 + 40);
	infoheader[0] = (unsigned char)40;
	infoheader[4] = (unsigned char)(rc->map.w);
	infoheader[5] = (unsigned char)(rc->map.w >> 8);
	infoheader[6] = (unsigned char)(rc->map.w >> 16);
	infoheader[7] = (unsigned char)(rc->map.w >> 24);
	infoheader[8] = (unsigned char)(rc->map.h);
	infoheader[9] = (unsigned char)(rc->map.h >> 8);
	infoheader[10] = (unsigned char)(rc->map.h >> 16);
	infoheader[11] = (unsigned char)(rc->map.h >> 24);
	infoheader[12] = (unsigned char)1;
	infoheader[14] = (unsigned char)24;
}

void				write_bits(t_raycast *rc, int padding, int fd)
{
	int				i;
	int				j;
	int				color;
	unsigned char	zero[3];

	ft_bzero(zero, 3);
	i = rc->map.h - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < rc->map.w)
		{
			color = get_pixel(&rc->img, j, i);
			write(fd, &color, 3);
			j++;
		}
		if (padding > 0)
			write(fd, &zero, padding);
		i--;
	}
}

void				screenshot(t_raycast *rc)
{
	int				fd;
	unsigned char	fileheader[14];
	unsigned char	infoheader[40];
	int				filesize;
	int				padding;

	if ((fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0777)) < 0)
	{
		perror("Couldn't create de bmp file");
		return ;
	}
	ft_bzero(fileheader, 14);
	ft_bzero(infoheader, 40);
	padding = (4 - (3 * rc->map.w) % 4) % 4;
	filesize = 40 + 14 + (3 * rc->map.w + padding) \
				* rc->map.h;
	create_header(rc, fileheader, infoheader, filesize);
	write(fd, &fileheader, 14);
	write(fd, &infoheader, 40);
	write_bits(rc, padding, fd);
}
