# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/17 11:38:38 by fportalo          #+#    #+#              #
#    Updated: 2020/12/17 12:04:35 by fportalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = -gcc


FLAGS = -Werror -Wextra -Wall -g

TEST = -Imlx mlx_test.c -Lmlx -lmlx -framework OpenGL -framework AppKit

test:
	@$(CC)  $(FLAGS) $(TEST)
