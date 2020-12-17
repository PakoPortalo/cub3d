/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamagotchi <tamagotchi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:38:27 by fportalo          #+#    #+#             */
/*   Updated: 2020/12/16 17:16:38 by tamagotchi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_save_flag(int argc, char **argv)
{
	char	*savecheck;
	int		i;

	if (argc == 3)
	{
		savecheck = "--save";
		i = 0;
		while (argv[2][i])
		{
			if (argv[2][i] != savecheck[i])
			{
				perror("Error\nPlease introduce \"--save\" after map's name");
				exit (1);
			}
			i++;
		}
	}
}

int		check_extension(char *file, char *ext)
{
	int		i;
	int		j;
	char	*fext;

	i = ft_strlen(file) - 1;
	j = 4;
	fext = malloc(4);
	fext[j] = '\0';
	j--;
	while( j > 0)
	{
		fext[j] = file[i];
		i--;
		j--;
	}
	fext[j] = file[i];

	if (ft_strncmp(fext, ext, 4) != 0)
		return(-1);
	return (1);
}

void		check_number_arguments(int argc)
{
	if (argc != 2 && argc != 3)
	{
		perror("Error\nPlease introduce a correct number of arguments");
		exit (1);
	}
}

void		check_ini_errors(int argc, char **argv)
{
	check_number_arguments(argc);
	if (check_extension(argv[1], ".cub") == -1)
	{
		perror("Error\nPlease introduce a valid extension");
		exit (1);
	}
	check_save_flag(argc, argv);
}
