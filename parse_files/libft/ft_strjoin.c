/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:46:30 by fportalo          #+#    #+#             */
/*   Updated: 2019/12/10 19:07:30 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	j;
	unsigned int	k;
	char			*p;

	j = 0;
	k = 0;
	if (!s1)
		return (NULL);
	p = malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
	if (!p)
		return (0);
	while (s1[j] != '\0')
	{
		p[j] = s1[j];
		j++;
	}
	while (s2[k] != '\0')
		p[j++] = s2[k++];
	p[j] = '\0';
	return (p);
}
