/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:46:03 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/11 15:00:54 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	z.x = 0.0;
	z.y = 0.0;
	c.x = map(x, -2.0, +2.0, WIN_WIDTH);
	c.y = map(y, +2.0, -2.0, WIN_HEIGHT);
	while (++i < engine->fractal.max_iter)
	{
		z = complex_sum(complex_square(z), c);
		if (z.x * z.x + z.y * z.y > engine->fractal.esc_value)
		{
			color = map(i, BLACK, WHITE, engine->fractal.max_iter);
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
}
