/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:24:44 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/08 12:00:16 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>

//para utilizar open
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx_linux/mlx.h"

//para utilizar close
# include <unistd.h>

//para utilizar maths
# include <math.h>

//po eso'
# include "gnl/get_next_line.h"
# include "libft/libft.h"

typedef struct mapstr {
	char	*res;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	char	*floor;
	char	*ceil;
	char	**map;
	int		rows;
	int		varnum;
	int x;
	int y;
} mapstr;


typedef struct mapclean {
	int		w;
	int		h;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	int		floor[3];
	int		ceil[3];
	char	**map;
	int		x;
	int		y;
	char	orientation;
} mapclean;

typedef struct mapconfig
{
	int res;
	int north;
	int south;
	int west;
	int east;
	int sprite;
	int floor;
	int ceil;
} mapconfig;

typedef struct	s_data {
	void		*ptr;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			line_height;
	int			endian;
}				t_data;

typedef struct s_handlekeys {
	int	left;
	int	up;
	int	right;
	int	down;
	int rotLeft;
	int rotRight;
}		t_handlekeys;

typedef	struct s_tex_img {
	t_data	img;
	int		height;
	int		width;
	int		coordX;
	int		coordY;
}			t_tex_img;

typedef struct s_text {
	t_tex_img	textures[5];
}				t_tex;

typedef struct	s_raycast {
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	double		stepX;
	double		stepY;
	int			hit;
	int			side;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	double		moveSpeed;
	double		rotSpeed;
	// double		frameTime;
	// double		moveSpeed;
	// double		rotSpeed;
	double			oldDirX;
	double			oldPlaneX;
	t_data			img;
	mapclean		map;
	t_handlekeys	keys;
	t_tex			tex;
	int				texNum;
	double			wallX;
	int				texX;
	// double			step;
	// double			texPos;
	// int				texY;
}				t_raycast;

int		cub3d(int argc, char **argv);
void	check_ini_errors(int argc, char **argv);
int		check_extension(char *file, char *ext);
void	raw_info(char *file, mapstr *raw);
void	save_map_info(mapstr *raw, mapclean *map);
void	iniraw(mapstr *raw);
void	inimap(mapclean *map);
void	ininum(mapconfig *num);

void	iniraycast(t_raycast *rc);
void	map_to_rc(t_raycast *rc, mapclean *map);
void	img_to_rc(t_raycast *rc, t_data *img);


int		ft_nbrdigit(int i);
void	check_resolution(mapstr *raw, mapclean *map);
void	check_texture(mapstr *raw, mapclean *map);
int		check_north(mapstr *raw, mapclean *map);
void	check_floor_ceil(mapstr *raw, mapclean *map);
void	check_map(mapstr *raw, mapclean *map);
void	check_number_variables(char **rgb, int i);
void	comma_counter(char *str);
char	*floor_ceil_spaces(char *rgb);
char	*get_map_texture(char *rawtexture, char *maptexture);
void	get_texture(mapstr *raw, mapclean *map);
char	*check_spaces(char *texturepath);
void	number_textures(char **texture);
void	check_border(mapstr *raw, int y, int x);
void	get_coordinates(int *x, int *y, mapstr *raw, mapclean *map);
void	check_number_lines(mapstr *raw, mapconfig *num);
void	get_raws(char **path, int *num, char *line);
void	map_file_error(void);


int		raycast_start(t_raycast *rc);
int		raycast_maths(t_raycast *rc);
int		printer_cub3d(mapclean *map);
int		funky_func_keypress(int keycode, t_raycast *rc);
int		funky_func_keyrelease(int keycode, t_raycast *rc);
int		exit_win(int keycode);

void		print_square(t_data *data, int color);

void		inihandlekeys(t_handlekeys *keys);


#endif
