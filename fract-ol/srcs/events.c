/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:39:22 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/11 12:17:09 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key_press(int keycode, t_engine *engine)
{
	if (keycode == XK_Escape)
		ft_destroy_event(engine);
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
