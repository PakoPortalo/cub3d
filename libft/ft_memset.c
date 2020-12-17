/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:26:36 by fportalo          #+#    #+#             */
/*   Updated: 2019/11/25 12:19:02 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int count;

	count = 0;
	while (len > 0)
	{
		((char*)b)[count] = (unsigned char)c;
		len--;
		count++;
	}
	return (b);
}
