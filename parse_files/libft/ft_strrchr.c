/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:49:45 by fportalo          #+#    #+#             */
/*   Updated: 2019/11/29 18:00:42 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int count;

	count = ft_strlen(str) - 1;
	if (c == '\0')
		return ((char *)str + count + 1);
	while (count >= 0)
	{
		if (str[count] == (char)c)
			return ((char *)str + count);
		count--;
	}
	return (NULL);
}
