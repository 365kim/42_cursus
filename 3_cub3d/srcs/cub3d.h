/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:50:56 by mihykim           #+#    #+#             */
/*   Updated: 2020/11/09 14:41:01 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <signal.h>

# define TITLE "cub3D"
# define EMPTY '0'
# define WALL '1'
# define SPRITE '2'

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define SPR 4
# define FLOOR 5
# define CEILING 6

# define PI 3.1415926535897
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define TEX_WIDTH 256
# define TEX_HEIGHT 256

# define KEY_A 0
# define KEY_D 2
# define KEY_S 1
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_ESC 53

# define ON 1
# define OFF 0
# define SKIP 0
# define MAP_START -1
# define EMPTY_LINE '\0'

typedef struct	s_img
{
	void		*ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct	s_sprite
{
	double		x;
	double		y;
	double		distance;
}				t_spr;

typedef struct	s_ray
{
	double		camera_x;
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_num;
	double		wall_x;
	double		step;
	double		tex_pos;
	int			tex_x;
	int			tex_y;
}				t_ray;

typedef struct	s_sprite_ray
{
	double		x;
	double		y;
	double		inversion_detection;
	double		transform_x;
	double		transform_y;
	int			screen_x;
	int			v_move_screen;
	int			height;
	int			width;
	int			draw_start_x;
	int			draw_start_y;
	int			draw_end_x;
	int			draw_end_y;
	int			tex_x;
	int			tex_y;
}				t_spr_ray;

typedef struct	s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
	char		dir;
}				t_player;

typedef struct	s_tex
{
	char		*path[6];
	int			tile[6][TEX_HEIGHT * TEX_WIDTH];
	int			floor;
	int			ceiling;
}				t_tex;

typedef struct	s_all
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_tex		tex;
	t_player	player;
	t_ray		ray;
	t_spr_ray	s_ray;
	t_spr		*sprite;
	int			num_sprite;
	int			**buf;
	double		*z_buffer;
	int			fd;
	int			width;
	int			height;
	char		**map;
	int			map_width;
	int			map_height;
	char		*line;
	t_list		*lst;
}				t_all;

/*
**	cub3d.c
*/

int				main(int argc, char **argv);
void			check_save_option(int argc, char *option, int *save_flag);
void			init_all(t_all *s);
void			open_cub(char *file_name, t_all *s);

/*
**	f01_read_info.c
*/

void			read_info(t_all *s);
int				decide_what_to_store(t_all *s, char **info);
void			store_resolution(t_all *s, char *width, char *height);
void			store_texture(t_all *s, char *xpm_path, int flag);
void			store_color(t_all *s, char *rgb_with_comma, int flag);

/*
**	f02_read_map.c
*/

void			read_map(t_all *s, char *line);
void			allocate_map(t_all *s, t_list *curr);
void			store_map_as_array(t_all *s, t_list *curr);
void			create_player(t_all *s, int i, int j);

/*
**	f03_validate_info_map.c
*/

void			validate_info(t_all *s);
void			validate_map(t_all *s);
void			validate_map_horizontal(char **map, int width, int height);
void			validate_map_vertical(char **map, int width, int height);

/*
**	f04_rearrange_all.c
*/

int				rearrange_all(t_all *s);
void			apply_player_orientation(t_all *s);
void			allocate_buffer(t_all *s);
void			load_texture(t_all *s);
void			load_image(t_all *s, int *texture, char *path, t_img *img);

/*
** 	f05_set_sprite.c
*/

void			set_sprite(t_all *s);
void			set_pos_sprite(t_all *s, int i, int x, int y);
void			sort_sprite(t_all *s, t_player *p);
void			sort(t_all *s);
void			set_sprite_color(t_all *s, t_spr_ray *s_ray, int stripe);

/*
**	f06_run_program.c
*/

void			run_program(t_all *s);
int				detect_keypress(int key, t_all *s);
void			move_back_forth(t_all *s, t_player *p, double move_speed);
void			move_left_right(t_all *s, t_player *p, double move_speed);
void			rotate_player(t_player *p, double rot_speed);

/*
**	f07_execute_raycasting_loop.c
*/

int				execute_raycasting_loop(t_all *s);
void			raycast_background(t_all *s);
void			raycast_sprite(t_all *s, t_player *p);
void			render(t_all *s);

/*
**	f08_set_color_texture.c
*/
void			set_floor_ceiling_color(t_all *s);
void			set_wall_texture(t_player *p, t_ray *ray);
void			set_wall_color(t_all *s, t_ray *ray, int x);

/*
**	f09_raycast_background.c
*/

void			init_raycasting(t_all *s, t_player *p, t_ray *ray, int x);
void			calculate_step_direction(t_player *p, t_ray *ray);
void			perform_dda(t_all *s, t_ray *ray);
void			calculate_wall_distance(t_player *p, t_ray *ray);
void			calculate_wall_height(t_all *s, t_ray *ray);

/*
** 	f10_raycast_sprite.c
*/

void			translate_sprite(t_all *s,
						t_player *p, t_spr_ray *s_ray, int i);
void			calculate_sprite_height(t_all *s, t_spr_ray *s_ray);
void			calculate_sprite_width(t_all *s, t_spr_ray *s_ray);

/*
** 	f11_take_screenshot.c
*/

void			take_screenshot(t_all *s);
void			write_bmp_header(t_all *s, int fd, int size);
void			convert_int_to_char(unsigned char *start, int value);
void			write_data(t_all *s, int fd);

#endif
