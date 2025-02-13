/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:39:22 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/13 18:59:38 by unmugviolet      ###   ########.fr       */
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

int	ft_mouse_handle(int button, int x, int y, t_engine *engine)
{
	double	mouse_re;
	double	mouse_im;
	double	shift_x;
	double	shift_y;

	shift_x = engine->fractal.shift_x;
	shift_y = engine->fractal.shift_y;
	mouse_re = map(x, -2.0, +2.0, WIN_WIDTH) * engine->fractal.zoom + shift_x;
	mouse_im = map(y, +2.0, -2.0, WIN_HEIGHT) * engine->fractal.zoom + shift_y;
	if (button == 1)
		ft_track_julia(x, y, engine);
	if (button == 4 && engine->fractal.iter_nbr < MAX_ITER)
	{
		engine->fractal.zoom *= 0.95;
		shift_x = mouse_re + (shift_x - mouse_re) * 0.95;
		shift_y = mouse_im + (shift_y - mouse_im) * 0.95;
	}
	if (button == 5)
	{
		engine->fractal.zoom *= 1.05;
		shift_x = mouse_re + (shift_x - mouse_re) * 1.05;
		shift_y = mouse_im + (shift_y - mouse_im) * 1.05;
	}
	fractal_render(engine);
	return (EXIT_SUCCESS);
}

int	ft_key_press(int keycode, t_engine *engine)
{
	if (keycode == XK_Escape)
		ft_destroy_event(engine);
	if (keycode == XK_a && engine->fractal.iter_nbr < MAX_ITER)
		engine->fractal.iter_nbr += 10;
	if (keycode == XK_z && engine->fractal.iter_nbr > MIN_ITER)
		engine->fractal.iter_nbr -= 10;
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
