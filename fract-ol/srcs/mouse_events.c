/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:29:40 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/14 10:35:09 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_zoom_out(t_engine *engine, double mouse_re, double mouse_im)
{
	engine->fractal.zoom *= 0.95;
	engine->fractal.shift_x = mouse_re + (engine->fractal.shift_x - mouse_re)
		* 0.95;
	engine->fractal.shift_y = mouse_im + (engine->fractal.shift_y - mouse_im)
		* 0.95;
}

static void	handle_zoom_in(t_engine *engine, double mouse_re, double mouse_im)
{
	engine->fractal.zoom *= 1.05;
	engine->fractal.shift_x = mouse_re + (engine->fractal.shift_x - mouse_re)
		* 1.05;
	engine->fractal.shift_y = mouse_im + (engine->fractal.shift_y - mouse_im)
		* 1.05;
}

int	ft_mouse_handle(int button, int x, int y, t_engine *engine)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = map(x, -2.0, +2.0, WIN_WIDTH) * engine->fractal.zoom
		+ engine->fractal.shift_x;
	mouse_im = map(y, +2.0, -2.0, WIN_HEIGHT) * engine->fractal.zoom
		+ engine->fractal.shift_y;
	if (button == 1 && engine->fractal.zoom >= 1)
		ft_track_julia(x, y, engine);
	if (button == 4 && engine->fractal.iter_nbr < MAX_ITER)
		handle_zoom_out(engine, mouse_re, mouse_im);
	if (button == 5)
		handle_zoom_in(engine, mouse_re, mouse_im);
	fractal_render(engine);
	return (EXIT_SUCCESS);
}
