/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:14:10 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/28 15:17:25 by yguinio          ###   ########.fr       */
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
bool	get_textures(t_engine *cube, char **file);

/* ----------------------------------PARSING-------------------------------- */
bool	is_valid_input(int ac, char **av, t_engine *cube);
char	**get_map_file(char *filename);

/* ----------------------------------UTILS---------------------------------- */
void	ft_display_usage(void);
void	print_err_exit(char *err_msg, char *arg, t_engine *cube);
void	destroy_textures(t_engine *cube);
char 	*get_surface_value(char **file, char *orientation);
void	ft_free(void *ptr);
void	clean_all(t_engine *cube);

/* ----------------------------------CHECKS--------------------------------- */
bool	check_map_file(char *map_filename);
bool	check_textures(char **file);

#endif
