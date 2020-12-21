/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:42:35 by fportalo          #+#    #+#             */
/*   Updated: 2020/12/21 09:43:12 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_freearray(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (-1);
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (1);
}
