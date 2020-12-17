/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:17:43 by fportalo          #+#    #+#             */
/*   Updated: 2020/01/05 12:26:26 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		l;

	l = ft_strlen(s1);
	s2 = (char *)malloc(l + 1);
	if (s2)
	{
		ft_memcpy(s2, s1, l);
		s2[l] = '\0';
	}
	else
		return (0);
	return (s2);
}
