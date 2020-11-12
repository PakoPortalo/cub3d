# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/06 11:56:58 by fportalo          #+#    #+#              #
#    Updated: 2020/11/12 12:13:39 by fportalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = mlx

CC = -gcc

FLAGS = -Werror -Wextra -Wall

WIN = -Imlx mlx_window_test.c -Lmlx -lmlx -framework OpenGL -framework AppKit

TEST = -Imlx mlx_test.c -Lmlx -lmlx -framework OpenGL -framework AppKit

test:
	@$(CC) $(FLAGS) $(TEST)
