/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:38:27 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/23 10:02:59 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_save_flag(char **argv)
{
	char	*savecheck;
	int		i;

	savecheck = "--save";
	i = 0;
	while (savecheck[i])
	{
		if (argv[2][i] != savecheck[i])
		{
			printf("Arg error.\nPlease introduce \"--save\" after map's name\n");
			return (-1);
		}
		i++;
	}
	return (1);
}

int		check_map_extension(char **argv)
{
	char	*mapext;
	int		i;
	int		j;

	mapext = ".cub";
	i = ft_strlen(mapext);
	j = ft_strlen(argv[1]);

	while (i != -1)
	{
		if (argv[1][j] != mapext[i])
		{
			printf("Arg error.\nPlease introduce a valid map file\n");
			return(-1);
		}
		i--;
		j--;
	}
	return (1);
}

int		check_number_arguments(argc)
{
	if (argc != 2 && argc != 3)
	{
		printf("Arg error.\nPlease introduce a correct number of arguments\n");
		return (-1);
	}
	return (1);
}

int		check_ini_errors(int argc, char **argv)
{
	if (check_number_arguments(argc) == -1)
		return (-1);
	if (check_map_extension(argv) == -1)
		return (-1);
	if (argc == 3 && check_save_flag(argv) == -1)
		return (-1);
	return (1);
}
