/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:17:48 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/17 09:24:56 by unmugviolet      ###   ########.fr       */
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
    ft_draw_square(engine, (t_point){center.x, center.y}, engine->data.player.size, BLACK);
}

void	ft_draw_player(t_engine *engine)
{
	int		tile;
	t_point	center;
	t_point	end;

	tile = engine->data.map.tile_size;
    center.x = (int)(engine->data.player.pos.x * tile);
    center.y = (int)(engine->data.player.pos.y * tile);
	ft_draw_square(engine, (t_point){center.x, center.y}, engine->data.player.size, YELLOW);
	end.x = center.x + cos(engine->data.player.angle) * (tile / 2);
	end.y = center.y - sin(engine->data.player.angle) * (tile / 2);
	ft_draw_line(engine, center, end, BLACK);
}

/*
 *	Updates the player position using the `k_pressed` struct, it uses the `SPEED`
 *	and checks if there should be collision.
 *	@return(void)
 */
void	update_player_position(t_engine *engine)
{
	t_player	*player;
	char const	**map = (const char **)engine->data.map.array;
	int const	size = engine->data.map.tile_size;

	player = &engine->data.player;
	if (player->k_pressed[0] && !is_wall(map, (t_pos){player->pos.x, player->pos.y
			- (1 * SPEED)}, size))
	{
		ft_clear_player(engine);
		player->pos.y -= 1 * SPEED;
	}
	if (player->k_pressed[1] && !is_wall(map, (t_pos){player->pos.x, player->pos.y
			+ (1 * SPEED)}, size))
	{
		ft_clear_player(engine);
		player->pos.y += 1 * SPEED;
	}
	if (player->k_pressed[2] && !is_wall(map, (t_pos){player->pos.x - (1 * SPEED),
			player->pos.y}, size))
	{
		ft_clear_player(engine);
		player->pos.x -= 1 * SPEED;
	}
	if (player->k_pressed[3] && !is_wall(map, (t_pos){player->pos.x + (1 * SPEED),
			player->pos.y}, size))
	{
		ft_clear_player(engine);
		player->pos.x += 1 * SPEED;
	}
	if (player->k_pressed[4])
	{
		player->angle += ROTATION;
		if (player->angle > 2 * PI)
			player->angle -= 2 * PI;
	}
	if (player->k_pressed[5])
	{
		player->angle -= ROTATION;
		if (player->angle < 0)
			player->angle += 2 * PI;
	}
}
