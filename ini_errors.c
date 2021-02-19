/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:38:27 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/19 16:58:38 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_save_flag(int argc, char **argv, t_mapclean *map)
{
	char	*savecheck;
	int		i;

	if (argc == 3)
	{
		savecheck = "--save";
		i = 0;
		while (savecheck[i])
		{
			if (argv[2][i] != savecheck[i])
			{
				perror("Error\nPlease introduce \"--save\" after map's name");
				exit(1);
			}
			i++;
		}
		map->savecheck = 1;
	}
}

int			check_extension(char *file, char *ext)
{
	int		i;
	int		j;
	char	*fext;

	i = ft_strlen(file) - 1;
	j = 4;
	fext = ft_calloc(sizeof(char), 5);
	j--;
	while (j > 0)
	{
		fext[j] = file[i];
		i--;
		j--;
	}
	fext[j] = file[i];
	if (ft_strncmp(fext, ext, 4) != 0)
	{
		free(fext);
		return (-1);
	}
	free(fext);
	return (1);
}

void		check_number_arguments(int argc)
{
	if (argc != 2 && argc != 3)
	{
		perror("Error\nPlease introduce a correct number of arguments");
		exit(1);
	}
}

void		check_map_exist(char **argv)
{
	int		fd;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror("Error\nCannot find Map");
		close(fd);
		exit(4);
	}
	close(fd);
}

void		check_ini_errors(int argc, char **argv, t_mapclean *map)
{
	check_number_arguments(argc);
	if (check_extension(argv[1], ".cub") == -1)
	{
		perror("Error\nPlease introduce a valid extension");
		exit(1);
	}
	check_map_exist(argv);
	check_save_flag(argc, argv, map);
}
