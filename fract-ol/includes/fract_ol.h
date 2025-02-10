/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:52:11 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/10 11:30:58 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WIN_WIDTH 750
# define WIN_HEIGHT 500

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

void			ft_display_usage(void);

void			ft_init_engine(t_engine *engine, char *fractal);

int				ft_key_press(int keycode, t_engine *engine);
int				ft_destroy_event(t_engine *engine);

#endif
