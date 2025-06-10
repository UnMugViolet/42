/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:14:10 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/10 10:32:24 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "dictionnary.h"
# include <string.h>
# include <errno.h>

# define WIN_WIDTH 1080
# define WIN_HEIGHT 790

typedef struct s_check_map
{
	bool	n;
	bool	s;
	bool	e;
	bool	w;
	bool	f;
	bool	c;
}	t_check_map;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_data
{
	t_img	textures[4];
	t_img	test;	
}			t_data;

typedef struct s_engine
{
	void		*mlx;
	void		*win;
	t_data		data;
}				t_engine;

/* ----------------------------------EVENTS--------------------------------- */

int		ft_key_press(int keycode, t_engine *engine);
int		ft_destroy_event(t_engine *engine);

/* ----------------------------------INIT----------------------------------- */

void	ft_init_image(t_data *data, void *mlx);
void	ft_init_window(t_engine *engine, char *fractal);
void	ft_init_engine(t_engine *engine, char *fractal);
void	ft_init_game(t_engine *engine);
bool	get_textures(t_engine *engine, char *file);

/* ----------------------------------PARSING-------------------------------- */
bool	is_valid_input(int ac, char **av, t_engine *engine);
char	**get_map_file(char *filename);

/* ----------------------------------UTILS---------------------------------- */
void	ft_display_usage(void);
void	print_err_exit(char *err_msg, char *arg, t_engine *engine);
void	destroy_textures(t_engine *engine);
char	*get_surface_value(char **file, char const *orientation);
void	ft_free(void *ptr);
void	clean_all(t_engine *engine);
bool	get_new_image(t_engine *engine, char *path, t_img *image);
int		map_rows(char **map);
int		map_max_len(char **map);
bool	ft_is_charset(char c, char *charset);
char	**pad_map(char **map);
char	**extract_map(char **map_file);

/* ----------------------------------CHECKS--------------------------------- */
bool	check_map_file(char *map_filename);
bool	check_textures(char **file);
bool	check_color(char **file);
bool	extern_flood_fill(char **map, t_point size, t_point start);


/* ----------------------------------COLORS---------------------------------- */
int	encode_rgb(char red, char green, char blue);

#endif
