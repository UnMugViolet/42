/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:20:00 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/16 18:29:07 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_key_press(int keycode, t_engine *engine)
{
	if (keycode == XK_Escape)
		ft_destroy_event(engine);
	if (keycode == XK_w)
		engine->data.player.k_pressed[0] = 1;
	if (keycode == XK_s)
		engine->data.player.k_pressed[1] = 1;
	if (keycode == XK_a)
		engine->data.player.k_pressed[2] = 1;
	if (keycode == XK_d)
		engine->data.player.k_pressed[3] = 1;
	if (keycode == XK_Left)
		engine->data.player.k_pressed[4] = 1;
	if (keycode == XK_Right)
		engine->data.player.k_pressed[5] = 1;
	return (EXIT_SUCCESS);
}

int	ft_key_release(int keycode, t_engine *engine)
{
	if (keycode == XK_w)
		engine->data.player.k_pressed[0] = 0;
	if (keycode == XK_s)
		engine->data.player.k_pressed[1] = 0;
	if (keycode == XK_a)
		engine->data.player.k_pressed[2] = 0;
	if (keycode == XK_d)
		engine->data.player.k_pressed[3] = 0;
	if (keycode == XK_Left)
		engine->data.player.k_pressed[4] = 0;
	if (keycode == XK_Right)
		engine->data.player.k_pressed[5] = 0;
	return (EXIT_SUCCESS);
}

int	ft_destroy_event(t_engine *engine)
{
	clean_all(engine);
	exit(EXIT_SUCCESS);
}
