/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:14:10 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/26 10:12:46 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "dictionnary.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <math.h>
# include <stdbool.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_check_map
{
	bool		n;
	bool		s;
	bool		e;
	bool		w;
	bool		f;
	bool		c;
}				t_check_map;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct s_ray
{
	t_point		end;
	t_point		start;
	t_pos		hit;
	bool		is_vertical;
	double		len;
	double		angle;
}				t_ray;

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			h;
	int			w;
	int			bpp;
	int			endian;
	int			line_len;
}				t_img;

typedef struct s_player
{
	int			size;
	t_pos		pos;
	t_pos		dir;
	t_pos		plan;
	double		angle;
	bool		k_pressed[7];
	int			last_x_mouse;
}				t_player;

typedef struct s_map
{
	char		**array;
	t_point		size;
	t_img		textures[4];
	int			colors[2];
	t_img		wall;
}				t_map;

typedef struct s_data
{
	t_map		map;
	t_point		screen_size;
	t_player	player;
	t_img		img;
	t_ray		ray[WIN_W];
	int			tile;
}				t_data;

typedef struct s_engine
{
	void		*mlx;
	void		*win;
	t_data		data;
}				t_engine;

/* ----------------------------------EVENTS--------------------------------- */

int				ft_key_press(int keycode, t_engine *engine);
int				ft_key_release(int keycode, t_engine *engine);
int				ft_destroy_event(t_engine *engine);
int				ft_mouse_move(int x, int y, t_engine *engine);

/* ----------------------------------INIT----------------------------------- */

void			ft_init_image(t_data *data, void *mlx);
void			ft_init_window(t_engine *engine, char *fractal);
void			ft_init_engine(t_engine *engine, char *fractal);
void			ft_init_player(t_engine *engine);
bool			get_textures(t_engine *engine, char *file);
bool			get_colors(t_engine *engine, char *file_path);
void			ft_center_mouse(t_engine *engine);

/* ----------------------------------PARSING-------------------------------- */

bool			is_valid_input(int ac, char **av, t_engine *engine);
char			**get_map_file(char *filename);

/* ----------------------------------UTILS---------------------------------- */

void			destroy_textures(t_engine *engine);
char			*get_surface_value(char **file, char const *orientation);
bool			get_new_image(t_engine *engine, char *path, t_img *image);
int				map_rows(char **map);
int				map_max_len(char **map);
char			**pad_map(char **map);
char			**extract_map(char **map_file);

void			ft_free(void *ptr);
void			ft_display_usage(void);
size_t			ft_get_time_in_ms(void);
void			clean_all(t_engine *engine);
void			print_err_exit(char *err_msg, char *arg, t_engine *engine);

void			ft_angle_to_dir(double angle, t_pos *dir);
void			ft_set_t_point(t_point *p, int x, int y);
void			ft_set_t_pos(t_pos *p, double x, double y);
int				tile(int *tile_set);

/* ----------------------------------CHECKS--------------------------------- */

bool			check_map_file(char *map_filename);
bool			check_textures(char **file);
bool			check_color(char **file);
bool			extern_flood_fill(char **map, t_point size, t_point start);
bool			is_wall(t_engine *engine, t_pos position, int offset);
bool			is_equal(double a, double b);

/* ----------------------------------COLORS---------------------------------- */

int				encode_rgb(char *red, char *green, char *blue);

/* ----------------------------------RAYCAST--------------------------------- */
void			ft_check_vertical_angle(double angle, t_pos player, t_pos *ray,
					t_pos *step);
void			ft_check_horizontal_angle(double angle, t_pos player,
					t_pos *ray, t_pos *step);
double			ray_distance(t_engine *engine, t_pos ray);
void			ft_raycast(t_engine *engine);

t_pos			vertical_wall_hit(t_engine *engine, double angle);
t_pos			horizontal_wall_hit(t_engine *engine, double angle);
void			ft_set_rays(t_engine *engine, t_ray *ray, t_ray *ray_temp,
					double angle);
void			ft_copy_ray(t_ray *paste, t_ray *copy);
void			ft_select_shortest_ray(t_player *p, t_ray *ray, t_ray *temp);

/* ----------------------------------DISPLAY--------------------------------- */

int				game_loop(t_engine *engine);
int				ft_render(t_engine *engine);
void			ft_put_pixel(t_engine *engine, t_point init_point, int color);
void			ft_draw_square(t_engine *engine, t_point point, int width,
					int color);
void			ft_draw_line(t_engine *engine, t_point start, t_point end,
					int color);
void			ft_draw_map_2d(t_engine *engine);
void			ft_draw_player(t_engine *engine);
void			ft_clear_player(t_engine *engine);
void			ft_draw_map_3d(t_engine *engine);
void			draw_centered_triangle(t_engine *engine, t_pos pos,
					t_point dimension, int color);
void			ft_display_wall(t_engine *engine, int v_pxl, double angle,
					t_ray ray);

/* ---------------------------------MOVEMENTS-------------------------------- */

void			ft_handle_movement(t_engine *engine);
void			ft_rotation(t_engine *engine, char direction);

t_pos			ft_next_wall(t_engine *engine, t_pos pos, double angle);
t_pos			ft_hit_wall(t_engine *engine, t_player player);
bool			is_wall_at(char **map, float x, float y, int tile_size);

#endif
