/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:36:02 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/17 09:30:48 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static bool	is_wall_at(const char **map, float x, float y, int tile_size)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / tile_size);
	map_y = (int)(y / tile_size);
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
bool	is_wall(const char **map, t_pos pos, const int tile_size)
{
	float		px;
	float		py;
	float const	offset = tile_size / 3.0 / 2.0;

	px = pos.x * tile_size;
	py = pos.y * tile_size;
	if (is_wall_at(map, px - offset, py - offset, tile_size))
		return (true);
	if (is_wall_at(map, px + offset, py - offset, tile_size))
		return (true);
	if (is_wall_at(map, px - offset, py + offset, tile_size))
		return (true);
	if (is_wall_at(map, px + offset, py + offset, tile_size))
		return (true);
	return (false);
}
