# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/13 12:22:57 by fportalo          #+#    #+#              #
#    Updated: 2021/02/18 19:05:16 by fportalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = -o cub3D

FLAGS = -Werror -Wextra -Wall -I.

FILES = cub3d.c ini_errors.c ini_struct_1.c ini_struct_2.c map_clean.c resolution_map_clean.c \
		floorceil_map_clean.c check_map_clean.c texture_map_clean.c raw_map.c main.c \
		map_clean_utils1.c map_clean_utils2.c raw_map_utils.c paint.c load_textures.c \
		raycast.c raycast_calcs.c paint_tools.c paint_textures.c paint_sprites.c \
		save_sort_sprites.c screenshot.c

FILESMAC = hooks_mac.c

FILESLINUX = hooks_linux.c

GNL = gnl/get_next_line.c gnl/get_next_line_utils.c

LIBFT = -L ./libft/ -lft

INI = && ./cub3D maps/map.cub

UNAME := $(shell uname)

NORMI = norminette cub3d.h

ifeq ($(UNAME), Darwin)
	MLX :=  -Imlx_mac -Lmlx_mac -lmlx -framework OpenGL -framework AppKit

	LIBTOPATH = && cp libmlx.dylib
endif
ifeq ($(UNAME), Linux)
	MLX := -Imlx_linux -Lmlx_linux -lmlx -Imlx_linux -lXext -lX11
endif

ifeq ($(UNAME), Darwin)
all:
	@$(CC)  $(FLAGS) -g $(FILES) $(FILESMAC) $(GNL) -lm $(LIBFT) $(MLX) $(NAME) $(INI)
endif
ifeq ($(UNAME), Linux)
all:
	@$(CC) $(FLAGS) -g $(FILES) $(FILESLINUX) $(GNL) -lm $(LIBFT) $(MLX) $(NAME) $(INI)
endif

normi:
	@$(NORMI) $(FILES) $(FILESMAC) $(FILESLINUX)

debug:
	@$(CC)  $(FLAGS) -g3 -fsanitize=address $(FILESDEBUG) $(GNL) $(LIBFT) $(NAME) $(INI)
debug2:
	@$(CC)  $(FLAGS) -g3 $(FILESDEBUG) $(GNL) $(LIBFT) $(NAME) $(INI)

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

.PHONY: mlx libft
