/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:39:22 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/13 09:33:02 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mouse_handle(int button, int x, int y, t_engine *engine)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = map(x, -2.0, +2.0, WIN_WIDTH) * engine->fractal.zoom
		+ engine->fractal.shift_x;
	mouse_im = map(y, +2.0, -2.0, WIN_HEIGHT) * engine->fractal.zoom
		+ engine->fractal.shift_y;
	if (button == 4 && engine->fractal.iter_nbr < MAX_ITER)
	{
		engine->fractal.zoom *= 0.95;
		engine->fractal.shift_x = mouse_re + (engine->fractal.shift_x
				- mouse_re) * 0.95;
		engine->fractal.shift_y = mouse_im + (engine->fractal.shift_y
				- mouse_im) * 0.95;
	}
	if (button == 5)
	{
		engine->fractal.zoom *= 1.05;
		engine->fractal.shift_x = mouse_re + (engine->fractal.shift_x
				- mouse_re) * 1.05;
		engine->fractal.shift_y = mouse_im + (engine->fractal.shift_y
				- mouse_im) * 1.05;
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
	ft_printf("keycode: %i, XK_value: %i\n", keycode, XK_q);
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
