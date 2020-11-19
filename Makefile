# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/13 12:22:57 by fportalo          #+#    #+#              #
#    Updated: 2020/11/19 12:38:20 by fportalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = -gcc

FLAGS = -Werror -Wextra -Wall

PARSE = main.c -g parse_map.c check_map.c gnl/get_next_line.c gnl/get_next_line_utils.c

parse:
	@$(CC) $(FLAGS) $(PARSE)
