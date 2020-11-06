# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/06 11:56:58 by fportalo          #+#    #+#              #
#    Updated: 2020/11/06 12:05:24 by fportalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

CC = gcc

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		-@$(CC) -g $(FLAGS) -I. -c $(SRC)
		-@ar rc $(NAME) $(OBJ)
		-@ranlib $(NAME)

x:
		-@$(CC) -g -I. main.c libftprintf.a

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all
