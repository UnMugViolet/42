/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:17:48 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/12 11:34:28 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*
*	Set the player on the map according to the spawn point.
*	The direction is taken into account and the player `struct` stores the data
*	@return(void)   
*/
void	set_player_position(t_player *player, char **map)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_is_charset(map[i][j], "NSEW"))
			{
				player->pos.x = j + 0.5;
				player->pos.y = i + 0.5;
				if (map[i][j] == 'N')
					player->angle = 0;
				else if (map[i][j] == 'S')
					player->angle = PI;
				else if (map[i][j] == 'W')
					player->angle = (3 * PI) / 2;
				else if (map[i][j] == 'E')
					player->angle = PI / 2;
			}
		}
	}
}

/*
*	Updates the player position using the `wsad` struct, it uses the `SPEED`
*	and checks if there should be collision.
*	@return(void)
*/
void	update_player_position(t_engine *engine)
{
	t_player	*player;
	char const	**map = (const char **)engine->data.map.array;
	int const	size = engine->data.map.tile_size;

	player = &engine->data.player;
	if (player->wsad[0] && !is_wall(map, (t_pos){player->pos.x,
			player->pos.y - (1 * SPEED)}, size))
		player->pos.y -= 1 * SPEED;
	if (player->wsad[1] && !is_wall(map, (t_pos){player->pos.x,
			player->pos.y + (1 * SPEED)}, size))
		player->pos.y += 1 * SPEED;
	if (player->wsad[2] && !is_wall(map, (t_pos){player->pos.x - (1 * SPEED),
			player->pos.y}, size))
		player->pos.x -= 1 * SPEED;
	if (player->wsad[3] && !is_wall(map, (t_pos){player->pos.x + (1 * SPEED),
			player->pos.y}, size))
		player->pos.x += 1 * SPEED;
}
