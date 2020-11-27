/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:38:27 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/27 12:34:38 by fportalo         ###   ########.fr       */
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

int		check_extension(char *file, char *ext)
{
	int		i;
	int		j;
	char	*fext;

	i = 0;
	j = 0;
	fext = malloc(4);
	while (file[i] != '0' && ((file[i] != '.') || (file[i] == '.' && file[i + 1] == '/')))
		i++;
	while(file[i] != '\0')
	{
		fext[j] = file[i];
		i++;
		j++;
	}
	fext[j] = '\0';
	if (ft_strncmp(fext, ext, 5) != 0)
	{
		printf("Error. Please introduce a valid extension");
		return (-1);
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
	if (check_extension(argv[1], ".cub") == -1)
		return (-1);
	if (argc == 3 && check_save_flag(argv) == -1)
		return (-1);
	return (1);
}
