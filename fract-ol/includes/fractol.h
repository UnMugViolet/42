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
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define WIN_WIDTH 750
# define WIN_HEIGHT 500

typedef struct s_complex
{
	double		real;
	double		i;
}				t_complex;

typedef struct s_fractal
{
	char		*name;
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

int				ft_key_press(int keycode, t_engine *engine);
int				ft_destroy_event(t_engine *engine);

#endif
