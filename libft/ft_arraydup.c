/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:29:28 by user42            #+#    #+#             */
/*   Updated: 2021/02/04 13:29:32 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_arraydup(char **array, int rows)
{
	int		i;
	char	**matrix;

	i = 0;
	matrix = malloc(sizeof(char) * (rows));
	if (!array)
		return(NULL);
	while (i < rows)
	{
		matrix[i] = ft_strdup(array[i]);
		i++;
	}
	// matrix[i] = ft_strdup(array[i]);
	return(matrix);
}
