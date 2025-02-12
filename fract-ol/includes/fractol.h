/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:52:11 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/11 12:15:50 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define WIN_WIDTH 550
# define WIN_HEIGHT 550
# define MAX_ITER 320
# define MIN_ITER 10

# define BLACK 0x000000
# define WHITE 0xFFFFFF

typedef struct s_complex
{
	double		x;
	double		y;
}				t_complex;

typedef struct s_fractal
{
	char		*name;
	double		esc_value;
	int			iter_nbr;
	double		shift_x;
	double		shift_y;
	double		zoom;
}				t_fractal;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_data;

typedef struct s_engine
{
	void		*mlx;
	void		*win;
	t_data		data;
	t_fractal	fractal;
}				t_engine;

bool			is_valid_input(int ac, char *str);

void			ft_display_usage(void);

void			ft_init_engine(t_engine *engine, char *fractal);
void			ft_init_fractal(t_fractal *fractal, char *name);

int				ft_mouse_handle(int button, int x, int y, t_engine *engine);
int				ft_key_press(int keycode, t_engine *engine);
int				ft_destroy_event(t_engine *engine);

t_complex		complex_square(t_complex z);
t_complex		complex_sum(t_complex z1, t_complex z2);
double			map(double unsc_nb, double n_min, double n_max, double o_max);

void			fractal_render(t_engine *engine);

#endif
