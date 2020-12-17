/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:04:58 by fportalo          #+#    #+#             */
/*   Updated: 2019/11/29 16:53:03 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		if (((unsigned char *)s)[i] != (unsigned char)c)
			i++;
		else
		{
			s = s + i;
			return ((void *)s);
		}
		n--;
	}
	return (NULL);
}
