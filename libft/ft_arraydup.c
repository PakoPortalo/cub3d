/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:29:28 by user42            #+#    #+#             */
/*   Updated: 2021/01/28 11:37:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_arraydup(char **array)
{
	int x;
	char **duparray;

	x = 0;
	duparray = NULL;

	if (!array)
		return(NULL);
	while (array[x] != NULL)
	{
		duparray[x] = ft_strdup(array[x]);
		x++;
	}
	return(duparray);
}
