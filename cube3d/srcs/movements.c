/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:11:03 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/06/17 11:52:10 by unmugviolet      ###   ########.fr       */
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
	printf("Current position: x = %f, y = %f\n", player->pos.x, player->pos.y);
	printf("Next position: x = %f, y = %f\n", next_pos.x, next_pos.y);
	return (next_pos);
}

static void	ft_translate_player(t_engine *engine, char direction)
{
	t_player	*player;

	ft_clear_player(engine);
	player = &engine->data.player;
	player->pos = ft_get_player_next_pos(player, direction);
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
	int const	size = engine->data.map.tile_size;;

	player = &engine->data.player;
	if (player->k_pressed[0] && !is_wall(map, ft_get_player_next_pos(player, 'W'), size))
		ft_translate_player(engine, 'W');
	if (player->k_pressed[1] && !is_wall(map, ft_get_player_next_pos(player, 'S'), size))
		ft_translate_player(engine, 'S');		
	if (player->k_pressed[2] && !is_wall(map, ft_get_player_next_pos(player, 'A'), size))
		ft_translate_player(engine, 'A');
	
	if (player->k_pressed[3] && !is_wall(map, ft_get_player_next_pos(player, 'D'), size))
		ft_translate_player(engine, 'D');
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
