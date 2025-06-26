/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:36:02 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/26 10:33:49 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_wall_at(char **map, float x, float y, int tile_size)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / tile_size);
	map_y = (int)(y / tile_size);
	if (map_x <= 0 || map_x >= map_max_len(map) || \
		map_y <= 0 || map_y >= map_rows(map))
		return (true);
	if (map[map_y][map_x] == '1')
		return (true);
	return (false);
}

/*
 *	Using the player position and correct it by the offset a player is taken
 *	we will check if the player is trying to go where the wall at.
 *	If there is a wall then the player cannot move further.
 *	@return bool
 */
bool	is_wall(t_engine *engine, t_pos pos, int offset)
{
	float		px;
	float		py;
	char		**map;

	px = pos.x * engine->data.tile;
	py = pos.y * engine->data.tile;
	map = engine->data.map.array;
	if (pos.x < 0 || pos.x > map_max_len(map) || pos.y < 0
		|| pos.y > map_rows(map))
		return (true);
	if (is_wall_at(map, px - offset, py - offset, engine->data.tile))
		return (true);
	if (is_wall_at(map, px + offset, py - offset, engine->data.tile))
		return (true);
	if (is_wall_at(map, px - offset, py + offset, engine->data.tile))
		return (true);
	if (is_wall_at(map, px + offset, py + offset, engine->data.tile))
		return (true);
	return (false);
}
