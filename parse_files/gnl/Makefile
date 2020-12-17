# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/22 01:39:28 by fgata-va          #+#    #+#              #
#    Updated: 2020/11/16 11:17:46 by fportalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I . -g -D BUFFER_SIZE=100

SRC = get_next_line.c get_next_line_utils.c main.c

NAME = gnl

all: $(NAME)

$(NAME):
		@$(CC) $(CFLAGS) $(SRC)

fclean:
		@rm -f *.out

re: fclean all

.PHONY: all fclean re
