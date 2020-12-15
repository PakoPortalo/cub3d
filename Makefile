# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/13 12:22:57 by fportalo          #+#    #+#              #
#    Updated: 2020/12/07 09:52:15 by fportalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = -gcc

NAME = -o cub3D

FLAGS = -Werror -Wextra -Wall -g

PARSE = cub3D.c ini_errors.c ini_struct.c map_clean.c resolution_map_clean.c \
		floorceil_map_clean.c check_map_clean.c texture_map_clean.c raw_map.c main.c \
		gnl/get_next_line.c libft/libft.a

parse:
	@$(CC)  $(FLAGS) $(PARSE) $(NAME)
