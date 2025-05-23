/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:14:10 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 18:29:51 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WIN_WIDTH 750
# define WIN_HEIGHT 750

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data;

typedef struct s_engine
{
	void		*mlx;
	void		*win;
	t_data		data;
}				t_engine;

/* ----------------------------------EVENTS------------------------------------ */

int	ft_key_press(int keycode, t_engine *engine);
int	ft_destroy_event(t_engine *engine);

/* ----------------------------------INIT-------------------------------------- */

void	ft_init_image(t_data *data, void *mlx);
void	ft_init_window(t_engine *engine, char *fractal);
void	ft_init_engine(t_engine *engine, char *fractal);

/* ----------------------------------PARSING----------------------------------- */
bool	is_valid_input(int ac, char **av, t_engine *engine);

/* ----------------------------------UTILS------------------------------------- */
void	ft_display_usage(void);

#endif
