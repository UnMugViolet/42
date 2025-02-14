/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:22:35 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/14 12:30:45 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_display_mandelbrot(t_engine *engine, int x, int y)
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
	c.x = z.x;
	c.y = z.y;
	while (++i < engine->fractal.iter_nbr)
	{
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
