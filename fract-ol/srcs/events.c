/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:39:22 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/14 12:40:38 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_track_julia(int x, int y, t_engine *engine)
{
	engine->fractal.julia_x = map(x, -2.0, +2.0, WIN_WIDTH)
		* engine->fractal.zoom + engine->fractal.shift_x;
	engine->fractal.julia_y = map(y, +2.0, -2.0, WIN_HEIGHT)
		* engine->fractal.zoom + engine->fractal.shift_y;
	fractal_render(engine);
	return (EXIT_SUCCESS);
}

int	ft_key_press(int keycode, t_engine *engine)
{
	if (keycode == XK_Escape)
		ft_destroy_event(engine);
	if (keycode == XK_q && engine->fractal.iter_nbr < MAX_ITER)
		engine->fractal.iter_nbr += 1;
	if (keycode == XK_w && engine->fractal.iter_nbr > MIN_ITER)
		engine->fractal.iter_nbr -= 1;
	if (keycode == XK_Up)
		engine->fractal.shift_y += (0.1 * engine->fractal.zoom);
	if (keycode == XK_Down)
		engine->fractal.shift_y -= (0.1 * engine->fractal.zoom);
	if (keycode == XK_Left)
		engine->fractal.shift_x -= (0.1 * engine->fractal.zoom);
	if (keycode == XK_Right)
		engine->fractal.shift_x += (0.1 * engine->fractal.zoom);
	if (keycode == XK_r)
		ft_init_fractal(&engine->fractal, engine->fractal.name);
	fractal_render(engine);
	return (EXIT_SUCCESS);
}

int	ft_destroy_event(t_engine *engine)
{
	mlx_destroy_image(engine->mlx, engine->data.img);
	mlx_destroy_window(engine->mlx, engine->win);
	mlx_destroy_display(engine->mlx);
	free(engine->mlx);
	exit(EXIT_SUCCESS);
}
