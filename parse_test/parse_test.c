/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:44:22 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/13 13:07:14 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_test.h"

int parse_test(char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);

	if (fd == -1)
	{
		printf("No funciona\n");
		return(0);
	}
	else
	{
		printf("Funciona\n");
		while ((i = get_next_line(fd, &line)) > 0)
		{
			printf("%s\n", line);
			free(line);
		}
	}

	printf("%d\n", i);
	printf("%s\n", line);
	//free(line);
	close(fd);
	return (0);
}
