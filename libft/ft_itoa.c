/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:29:00 by fportalo          #+#    #+#             */
/*   Updated: 2019/12/16 16:29:07 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_revstr(char *str)
{
	char		tmp[13];
	int			i;
	int			j;

	i = 0;
	j = ft_strlen(str) - 1;
	if (str[i] == '-')
	{
		tmp[i] = '-';
		i++;
	}
	while (str[i] != '\0')
	{
		tmp[i] = str[j];
		i++;
		j--;
	}
	tmp[i] = '\0';
	str = ft_memcpy(str, tmp, ft_strlen(tmp));
	return (str);
}

char			*ft_itoa(int n)
{
	char		tmp[12];
	char		*rtmp;
	char		*str;
	int			i;
	long int	nb;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		tmp[i++] = '-';
		nb *= -1;
	}
	if (nb == 0)
		tmp[i++] = '0';
	while (nb > 0)
	{
		tmp[i] = ((nb % 10) + '0');
		nb /= 10;
		i++;
	}
	tmp[i] = '\0';
	rtmp = ft_revstr(tmp);
	str = ft_strdup(rtmp);
	return (str);
}
