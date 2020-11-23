# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/13 12:22:57 by fportalo          #+#    #+#              #
#    Updated: 2020/11/23 13:08:34 by fportalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = -gcc

FLAGS = -Werror -Wextra -Wall -g

PARSE =  cub3d.c cub3d.h ini_errors.c raw_map.c map_clean.c main.c gnl/get_next_line.c gnl/get_next_line_utils.c

parse:
	@$(CC) $(FLAGS) $(PARSE)
