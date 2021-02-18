/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:24:44 by fportalo          #+#    #+#             */
/*   Updated: 2021/02/18 17:34:17 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx_linux/mlx.h"
# include <unistd.h>
# include <math.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"

typedef struct		s_mapstr {
	char			*res;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*sprite;
	char			*floor;
	char			*ceil;
	char			**map;
	int				rows;
	int				varnum;
	int				x;
	int				y;
	int				sprite_count;
}					t_mapstr;

typedef struct		s_mapclean{
	int				w;
	int				h;
	int				max_w;
	int				max_h;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*sprite;
	int				floor[3];
	int				ceil[3];
	char			**map;
	int				x;
	int				y;
	char			orientation;
	int				sprite_count;
	int				rows;
	int				savecheck;
}					t_mapclean;

typedef struct		s_mapconfig{
	int				res;
	int				north;
	int				south;
	int				west;
	int				east;
	int				sprite;
	int				floor;
	int				ceil;
}					t_mapconfig;

typedef struct		s_sprite{
	double			x;
	double			y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				screen_x;
	int				screen_y;
	int				height;
	int				width;
	int				draw_start_x;
	int				draw_end_x;
	int				draw_start_y;
	int				draw_end_y;
	int				tex_x;
	int				tex_y;
	double			perpdist;
}					t_sprite;

typedef struct		s_data{
	void			*ptr;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				line_height;
	int				endian;
}					t_data;

typedef struct		s_handlekeys{
	int				left;
	int				up;
	int				right;
	int				down;
	int				rot_left;
	int				rot_right;
}					t_handlekeys;

typedef	struct		s_tex_img{
	t_data			img;
	int				height;
	int				width;
	int				coord_x;
	int				coord_y;
}					t_tex_img;

typedef struct		s_text{
	t_tex_img		textures[5];
}					t_tex;

typedef struct		s_raycast{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	double			step_x;
	double			step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			move_speed;
	double			rot_speed;
	double			old_dir_x;
	double			old_plane_x;
	t_data			img;
	t_mapclean		map;
	t_handlekeys	keys;
	t_tex			tex;
	int				tex_num;
	double			wall_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	int				tex_y;
	t_sprite		*sprite;
	double			*z_buffer;
}					t_raycast;

int					cub3d(int argc, char **argv);
void				check_ini_errors(int argc, char **argv, t_mapclean *map);
int					check_extension(char *file, char *ext);
void				raw_info(char *file, t_mapstr *raw, t_mapclean *map);
void				save_map_info(t_mapstr *raw, t_mapclean *map);
void				iniraw(t_mapstr *raw);
void				inimap(t_mapclean *map);
void				ininum(t_mapconfig *num);
void				iniraycast_1(t_raycast *rc);
void				iniraycast_2(t_raycast *rc);
void				map_to_rc(t_raycast *rc, t_mapclean *map);
void				img_to_rc(t_raycast *rc, t_data *img);
int					ft_nbrdigit(int i);
void				check_resolution(t_mapstr *raw, t_mapclean *map);
void				check_texture(t_mapstr *raw, t_mapclean *map);
int					check_north(t_mapstr *raw, t_mapclean *map);
void				check_floor_ceil(t_mapstr *raw, t_mapclean *map);
void				check_map(t_mapstr *raw, t_mapclean *map);
void				flood_fill_sub(t_mapstr *raw, int y, int x);
void				check_number_variables(char **rgb, int i);
void				comma_counter(char *str);
char				*floor_ceil_spaces(char *rgb);
char				*get_map_texture(char *rawtexture, char *maptexture);
void				get_texture(t_mapstr *raw, t_mapclean *map);
char				*check_spaces(char *texturepath);
void				number_textures(char **texture);
void				check_border(t_mapstr *raw, int y, int x);
void				get_coordinates(int *x, int *y, t_mapstr *raw, \
					t_mapclean *map);
void				check_number_lines(t_mapstr *raw, t_mapconfig *num, \
					t_mapclean *map);
void				get_raws(char **path, int *num, char *line);
void				map_file_error(void);
char				*handle_spaces(char *line);
int					raycast_start(t_raycast *rc);
int					raycast_maths(t_raycast *rc);
int					printer_cub3d(t_mapclean *map);
int					funky_func_keypress(int keycode, t_raycast *rc);
int					funky_func_keyrelease(int keycode, t_raycast *rc);
int					exit_win(int keycode);
void				print_square(t_data *data, int color);
void				inisprite(t_sprite *sprite);
void				inihandlekeys(t_handlekeys *keys);
void				sort_sprites(t_raycast *rc);
void				inisprite(t_sprite *s);
void				save_sprites(t_raycast *rc);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				buffer_pixel(t_data *data, int x, int y, int color);
int					get_pixel(t_data *data, int x, int y);
int					rgb_to_hex(int t, int r, int g, int b);
void				ft_buffer(t_raycast *rc, int x);
void				buffer_line(t_raycast *rc, t_tex_img *tex, int x, \
					int line_height);
void				sprite_calc(t_raycast *rc, t_sprite *sprite, int i);
void				stripe_put(t_raycast *rc, t_sprite *sprite, \
					int x, t_tex_img *tex);
void				ft_sprites(t_raycast *rc);
void				ft_raydir(t_raycast *rc, int x);
void				ft_deltadist(t_raycast *rc);
void				ft_sidedist(t_raycast *rc);
void				ft_rayhit(t_raycast *rc);
void				ft_walldist(t_raycast *rc);
void				swap_swap(t_sprite *ptr1, t_sprite *ptr2);
void				sort_sprites(t_raycast *rc);
void				save_sprites(t_raycast *rc);
void				load_all_textures(t_raycast *rc);
void				screenshot(t_raycast *rc);

#endif
