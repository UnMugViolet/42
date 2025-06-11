/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:18:09 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/11 16:29:59 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static bool	is_wall_at(char **map, float x, float y, int tile_size)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / tile_size);
	map_y = (int)(y / tile_size);
	if (map_y < 0 || map_x < 0 || !map[map_y] || map[map_y][map_x] == '\0')
		return (true);
	if (map[map_y][map_x] == '1')
		return (true);
	return (false);
}

bool	is_wall(char **map, t_pos pos, int tile_size)
{
	float	offset;

	offset = tile_size / 3.0 / 2.0;
	if (is_wall_at(map, pos.x - offset, pos.y - offset, tile_size))
		return (true);
	if (is_wall_at(map, pos.x + offset, pos.y - offset, tile_size))
		return (true);
	if (is_wall_at(map, pos.x - offset, pos.y + offset, tile_size))
		return (true);
	if (is_wall_at(map, pos.x + offset, pos.y + offset, tile_size))
		return (true);
	return (false);
}
