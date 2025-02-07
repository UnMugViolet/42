/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:52:11 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/07 15:13:26 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_data;

typedef struct s_engine
{
	void	*mlx;
	void	*win;
	t_data	data;
}			t_engine;

void		ft_display_usage(void);

void		ft_exit_free(t_engine *engine);

void		ft_init_engine(t_engine *engine, char *fractal);

#endif
