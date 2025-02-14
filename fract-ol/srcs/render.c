/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:46:03 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/14 12:35:15 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_display_text(t_engine *engine)
{
	char	*iter_nbr;
	char	*julia_x;
	char	*julia_y;

	iter_nbr = ft_itoa(engine->fractal.iter_nbr);
	julia_x = ft_dtoa(engine->fractal.julia_x, 4);
	julia_y = ft_dtoa(engine->fractal.julia_y, 4);
	mlx_string_put(engine->mlx, engine->win, 10, 15, WHITE, "Iterations:");
	mlx_string_put(engine->mlx, engine->win, 80, 15, WHITE, iter_nbr);
	if (!ft_strncmp(engine->fractal.name, "julia", 6))
	{
		mlx_string_put(engine->mlx, engine->win, 680, 15, WHITE, "X:");
		mlx_string_put(engine->mlx, engine->win, 700, 15, WHITE, julia_x);
		mlx_string_put(engine->mlx, engine->win, 680, 30, WHITE, "Y:");
		mlx_string_put(engine->mlx, engine->win, 700, 30, WHITE, julia_y);
	}
	ft_clean_displayed_string(iter_nbr, julia_x, julia_y);
}

void	ft_put_pixel(t_engine *engine, int x, int y, int color)
{
	int	offset;

	offset = (y * engine->data.line_len + x * (engine->data.bpp / 8));
	*(unsigned int *)(engine->data.addr + offset) = color;
}

static void	handle_pixel(t_engine *engine, int x, int y)
{
	if (!ft_strncmp(engine->fractal.name, "mandelbrot", 11))
		ft_display_mandelbrot(engine, x, y);
	if (!ft_strncmp(engine->fractal.name, "julia", 6))
		ft_display_julia(engine, x, y);
	if (!ft_strncmp(engine->fractal.name, "burningship", 12))
		ft_display_burningship(engine, x, y);
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
	ft_display_text(engine);
}
