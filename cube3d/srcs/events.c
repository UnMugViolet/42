/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:20:00 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/11 13:59:57 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_key_press(int keycode, t_engine *engine)
{
	if (keycode == XK_Escape)
		ft_destroy_event(engine);
	if (keycode == XK_w)
		engine->data.player.wsad[0] = 1;
	if (keycode == XK_s)
		engine->data.player.wsad[1] = 1;
	if (keycode == XK_a)
		engine->data.player.wsad[2] = 1;
	if (keycode == XK_d)
		engine->data.player.wsad[3] = 1;
	return (EXIT_SUCCESS);
}

int	ft_key_release(int keycode, t_engine *engine)
{
	if (keycode == XK_w)
		engine->data.player.wsad[0] = 0;
	if (keycode == XK_s)
		engine->data.player.wsad[1] = 0;
	if (keycode == XK_a)
		engine->data.player.wsad[2] = 0;
	if (keycode == XK_d)
		engine->data.player.wsad[3] = 0;
	return (EXIT_SUCCESS);
}

int	ft_destroy_event(t_engine *engine)
{
	clean_all(engine);
	exit(EXIT_SUCCESS);
}
