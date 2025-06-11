/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:27:53 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/11 17:50:30 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	game_loop(t_engine *engine)
{
	double const	current_time = ft_get_time_in_ms();
	static double	last_frame;
	double			delta_time;

	delta_time = 0;
	if (!last_frame)
		last_frame = current_time;
	delta_time = (current_time - last_frame) / 1000;
	if (delta_time >= 0.005)
	{
		ft_render(engine);
		last_frame = current_time;
	}
	return (0);
}

int	ft_render(t_engine *engine)
{
	t_player	*player;
	t_point		pos;

	update_player_position(engine);
	player = &engine->data.player;
	pos.x = player->pos.x - (player->image.w / 2);
	pos.y = player->pos.y - (player->image.h / 2);
	mlx_clear_window(engine->mlx, engine->win);
	ft_display_map_2d(engine);
	mlx_put_image_to_window(engine->mlx, engine->win, player->image.img_ptr,
		pos.x, pos.y);
	return (0);
}
