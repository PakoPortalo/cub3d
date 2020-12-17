/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:49:01 by fportalo          #+#    #+#             */
/*   Updated: 2019/12/06 13:34:13 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int i;

	i = 0;
	if (n > 0)
	{
		while (n > 0)
		{
			if ((((unsigned char *)s1)[i] - ((unsigned char*)s2)[i]) != 0)
				return (((unsigned char *)s1)[i] - ((unsigned char*)s2)[i]);
			i++;
			n--;
		}
	}
	return (0);
}
