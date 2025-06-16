/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:27:53 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/16 16:32:45 by unmugviolet      ###   ########.fr       */
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
	update_player_position(engine);
	ft_draw_map_2d(engine);
	ft_draw_player(engine);
	mlx_put_image_to_window(engine->mlx, engine->win, engine->data.img.img_ptr,
		0, 0);
	return (0);
}
