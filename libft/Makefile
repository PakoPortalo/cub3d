# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 00:04:55 by fportalo          #+#    #+#              #
#    Updated: 2021/01/28 11:30:06 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memccpy.c ft_memcpy.c ft_putchar.c ft_putchar_fd.c \
ft_putstr.c ft_putstr_fd.c  ft_strjoin.c ft_strlen.c ft_strnstr.c ft_substr.c ft_bzero.c \
ft_isalpha.c ft_isprint.c ft_memchr.c ft_memmove.c ft_putendl_fd.c ft_strchr.c \
ft_strlcat.c ft_strmapi.c ft_strrchr.c ft_tolower.c ft_calloc.c ft_isascii.c \
ft_itoa.c ft_memcmp.c ft_memset.c ft_putnbr.c ft_putnbr_fd.c ft_strdup.c ft_strlcpy.c ft_strncmp.c \
ft_strtrim.c ft_toupper.c ft_split.c ft_freearray.c ft_arraydup.c

BONUSOBJS = $(BONUSSRC:.c=.o)

OBJ = $(SRC:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME):
		@$(CC) $(CFLAGS) -c $(SRC)
		@ar rc $(NAME) $(OBJ)

bonus:
		@$(CC) $(CFLAGS) -c $(BONUSSRC) $(SRC)
		@ar rc $(NAME) $(OBJ) $(BONUSOBJS)

clean:
		@rm -f $(OBJ)
		@rm -f $(BONUSOBJS)

fclean: clean
		@rm -f $(NAME)
		@rm -f $(SONAME)

re: fclean all

.PHONY: all clean fclean re
