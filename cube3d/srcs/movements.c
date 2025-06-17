/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:11:03 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/06/17 12:25:22 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_pos	ft_get_player_next_pos(t_player *player, char direction)
{
	t_pos	next_pos;

	if (direction == 'W')
	{
		next_pos.x = player->pos.x + cos(player->angle) * (1 * SPEED);
		next_pos.y = player->pos.y - sin(player->angle) * (1 * SPEED);
	}
	if (direction == 'S')
	{
		next_pos.x = player->pos.x - cos(player->angle) * (1 * SPEED);
		next_pos.y = player->pos.y + sin(player->angle) * (1 * SPEED);
	}
	if (direction == 'A')
	{
		next_pos.x = player->pos.x - sin(player->angle) * (1 * SPEED);
		next_pos.y = player->pos.y - cos(player->angle) * (1 * SPEED);
	}
	if (direction == 'D')
	{
		next_pos.x = player->pos.x + sin(player->angle) * (1 * SPEED);
		next_pos.y = player->pos.y + cos(player->angle) * (1 * SPEED);
	}
	return (next_pos);
}

static void	ft_translate_player(t_engine *engine, char direction)
{
	t_player	*player;

	player = &engine->data.player;
	if (ft_is_charset(direction, "WASD"))
	{
		ft_clear_player(engine);
		player->pos = ft_get_player_next_pos(player, direction);
	}
	else if (direction == 'L')
	{
		player->angle += ROTATION;
		if (player->angle > 2 * PI)
			player->angle -= 2 * PI;
	}
	else if (direction == 'R')
	{
		player->angle -= ROTATION;
		if (player->angle < 0)
			player->angle += 2 * PI;
	}
}

/*
 *	Updates the player position using the `k_pressed` struct,
 *	it uses the `SPEED`
 *	and checks if there should be collision.
 *	@return(void)
 */
void	ft_handle_movement(t_engine *engine)
{
	t_player	*player;
	char const	**map = (const char **)engine->data.map.array;
	int const	size = engine->data.map.tile_size;

	player = &engine->data.player;
	if (player->k_pressed[0] && !is_wall(map, ft_get_player_next_pos(player,
				'W'), size))
		ft_translate_player(engine, 'W');
	if (player->k_pressed[1] && !is_wall(map, ft_get_player_next_pos(player,
				'S'), size))
		ft_translate_player(engine, 'S');
	if (player->k_pressed[2] && !is_wall(map, ft_get_player_next_pos(player,
				'A'), size))
		ft_translate_player(engine, 'A');
	if (player->k_pressed[3] && !is_wall(map, ft_get_player_next_pos(player,
				'D'), size))
		ft_translate_player(engine, 'D');
	if (player->k_pressed[4])
		ft_translate_player(engine, 'L');
	if (player->k_pressed[5])
		ft_translate_player(engine, 'R');
}
