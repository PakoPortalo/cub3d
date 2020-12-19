# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamagotchi <tamagotchi@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/13 12:22:57 by fportalo          #+#    #+#              #
#    Updated: 2020/12/19 19:06:23 by tamagotchi       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = -o cub3D

FLAGS = -Werror -Wextra -Wall -I.

FILES = cub3D.c ini_errors.c ini_struct.c map_clean.c resolution_map_clean.c \
		floorceil_map_clean.c check_map_clean.c texture_map_clean.c raw_map.c main.c \
		mlx_test.c

GNL = gnl/get_next_line.c gnl/get_next_line_utils.c

LIBFT = -L ./libft/ -lft

INI = && ./cub3D map.cub

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
	MLX :=  -Imlx_mac mlx_test.c -Lmlx -lmlx -framework OpenGL -framework AppKit 
endif




ifeq ($(UNAME), Linux)
	MLX := -Imlx_linux -Lmlx_linux -lmlx -Imlx_linux -lXext -lX11
endif



all:
	@$(CC)  $(FLAGS) -g $(FILES) $(GNL) $(LIBFT) $(MLX) $(NAME)

libft: 
	@$(MAKE) -C libft all clean


ifeq ($(UNAME), Darwin)
mlx: 
	@$(MAKE) -C mlx_mac all
endif
ifeq ($(UNAME), Linux)
mlx: 
	@$(MAKE) -C mlx_linux all
endif

	
debug:
	@$(CC)  $(FLAGS) $(FILES) $(NAME) $(INI)

.PHONY: mlx libft