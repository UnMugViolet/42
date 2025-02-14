/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:22:35 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/14 18:44:13 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_complex(t_complex *z, t_complex *c)
{
	c->x = z->x;
	c->y = -z->y;
}

void	ft_display_burningship(t_engine *engine, int x, int y)
{
	int			i;
	int			color;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.x = (map(x, -2.0, +2.0, WIN_WIDTH) * engine->fractal.zoom
			+ engine->fractal.shift_x);
	z.y = (map(y, +2.0, -2.0, WIN_HEIGHT) * engine->fractal.zoom
			+ engine->fractal.shift_y);
	handle_complex(&z, &c);
	while (++i < engine->fractal.iter_nbr)
	{
		z.x = ft_fabs(z.x);
		z.y = ft_fabs(z.y);
		z = complex_sum(complex_square(z), c);
		if (z.x * z.x + z.y * z.y > engine->fractal.esc_value)
		{
			color = map(i, BLACK, WHITE, engine->fractal.iter_nbr);
			ft_put_pixel(engine, x, y, color);
			return ;
		}
	}
	ft_put_pixel(engine, x, y, BLACK);
}
