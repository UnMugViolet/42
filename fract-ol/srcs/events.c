/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:39:22 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/12 11:51:13 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mouse_handle(void)
{
	return (EXIT_SUCCESS);
}

int	ft_key_press(int keycode, t_engine *engine)
{
	if (keycode == XK_Escape)
		ft_destroy_event(engine);
	if (keycode == XK_KP_Add && engine->fractal.max_iter < 1000)
		engine->fractal.max_iter += 10;
	if (keycode == XK_KP_Subtract && engine->fractal.max_iter > 10)
		engine->fractal.max_iter -= 10;
	ft_printf("Keypressed: %i\nesc_value: %i\n", keycode ,engine->fractal.max_iter);
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
