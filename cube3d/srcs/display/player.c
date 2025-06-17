/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:17:48 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/17 11:34:39 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_clear_player(t_engine *engine)
{
	int		tile;
	t_point	center;

	tile = engine->data.map.tile_size;
	center.x = (int)(engine->data.player.pos.x * tile);
	center.y = (int)(engine->data.player.pos.y * tile);
	ft_draw_square(engine, (t_point){center.x, center.y},
		engine->data.player.size, BLACK);
}

void	ft_draw_player(t_engine *engine)
{
	int		tile;
	t_point	center;
	t_point	end;

	tile = engine->data.map.tile_size;
	center.x = (int)(engine->data.player.pos.x * tile);
	center.y = (int)(engine->data.player.pos.y * tile);
	ft_draw_square(engine, (t_point){center.x, center.y},
		engine->data.player.size, YELLOW);
	end.x = center.x + cos(engine->data.player.angle) * (tile / 2);
	end.y = center.y - sin(engine->data.player.angle) * (tile / 2);
	ft_draw_line(engine, center, end, BLACK);
}
