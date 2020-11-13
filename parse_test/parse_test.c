/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:44:22 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/13 12:10:37 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_test.h"

int parse_test(char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_WRONLY);

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
			//free(line);
		}
	}
	printf("%s\n", line);
	//free(line);
	close(fd);
	return (i);
}
