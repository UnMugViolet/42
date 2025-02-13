/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:46:03 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/13 18:52:48 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_mandel_vs_julia(t_complex *z, t_complex *c, t_engine *engine)
{
	if (!ft_strncmp(engine->fractal.name, "mandelbrot", 11))
	{
		c->x = z->x;
		c->y = z->y;
	}
	else
	{
		c->x = engine->fractal.julia_x;
		c->y = engine->fractal.julia_y;
	}
}

static void	ft_put_pixel(t_engine *engine, int x, int y, int color)
{
	int	offset;

	offset = (y * engine->data.line_len + x * (engine->data.bpp / 8));
	*(unsigned int *)(engine->data.addr + offset) = color;
}

static void	handle_pixel(t_engine *engine, int x, int y)
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
	ft_mandel_vs_julia(&z, &c, engine);
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

void	fractal_render(t_engine *engine)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			handle_pixel(engine, x, y);
	}
	mlx_put_image_to_window(engine->mlx, engine->win, engine->data.img, 0, 0);
	mlx_string_put(engine->mlx, engine->win, 10, 10, WHITE, "Iterations:");
	mlx_string_put(engine->mlx, engine->win, 80, 10, WHITE,
		ft_itoa(engine->fractal.iter_nbr));
}
