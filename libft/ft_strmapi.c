/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:24:48 by fportalo          #+#    #+#             */
/*   Updated: 2019/12/13 18:54:33 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*t;

	if (!s || !f)
		return (NULL);
	if (!(t = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(char))))
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		t[i] = f(i, s[i]);
		i++;
	}
	t[i] = '\0';
	return (t);
}
