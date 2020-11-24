# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/13 12:22:57 by fportalo          #+#    #+#              #
#    Updated: 2020/11/24 12:12:09 by fportalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = -gcc

FLAGS = -Werror -Wextra -Wall -g

PARSE =  cub3d.c cub3d.h ini_errors.c ini_struct.c map_clean.c check_map_clean.c raw_map.c main.c gnl/get_next_line.c libft/libft.a

parse:
	@$(CC) $(FLAGS) $(PARSE)
