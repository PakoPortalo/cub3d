/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:06:26 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/06 12:18:27 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int		main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
	mlx_loop(mlx);
}
