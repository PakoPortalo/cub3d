/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamagotchi <tamagotchi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:54:23 by fportalo          #+#    #+#             */
/*   Updated: 2020/12/20 13:09:45 by tamagotchi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_freearray(char **array)
{
    int i;

    i = 0;
    if (!array)
        return(-1);
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
    return (1);
}