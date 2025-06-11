/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:20:00 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/11 13:42:33 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_key_press(int keycode, t_engine *engine)
{
	if (keycode == XK_Escape)
		ft_destroy_event(engine);
	if (keycode == XK_w || keycode == XK_Up)
		engine->data.player.pos.y -= engine->data.player.image.h;
	if (keycode == XK_s || keycode == XK_Down)
		engine->data.player.pos.y += engine->data.player.image.h;
	if (keycode == XK_a || keycode == XK_Left)
		engine->data.player.pos.x -= engine->data.player.image.w;
	if (keycode == XK_d || keycode == XK_Right)
		engine->data.player.pos.x += engine->data.player.image.w;
	ft_render(engine);
	return (EXIT_SUCCESS);
}

int	ft_destroy_event(t_engine *engine)
{
	clean_all(engine);
	exit(EXIT_SUCCESS);
}
