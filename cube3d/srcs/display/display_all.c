/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:26:32 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/06/23 14:57:17 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_draw_map_2d(t_engine *engine)
{
/* 	int	i;
	int	j;

	i = -1;
	while (++i < map_rows(engine->data.map.array))
	{
		j = -1;
		while (++j < map_max_len(engine->data.map.array))
		{
			if (engine->data.map.array[i][j] == '1')
				ft_draw_square(engine, (t_point){j * engine->data.map.tile_size,  i * engine->data.map.tile_size}, engine->data.map.tile_size, WHITE);
			else if (engine->data.map.array[i][j] != ' ')
				ft_draw_square(engine, (t_point){j * engine->data.map.tile_size,  i * engine->data.map.tile_size}, engine->data.map.tile_size, RED);
		}
	} */
/* 	t_point tmp;

	tmp.x = engine->data.player.pos.x * engine->data.map.tile_size;
	tmp.y = engine->data.player.pos.y * engine->data.map.tile_size;
	
	ft_draw_square(engine, tmp, 10, RED);
	t_point pos, pos_next;
	
	pos.x = tmp.x;
	pos.y = tmp.y;

	pos_next.x = pos.x + 15 * engine->data.player.dir.x;
	pos_next.y = pos.y + 15 * engine->data.player.dir.y;
	
	ft_draw_line(engine, pos, pos_next, YELLOW); */
	int		tile_size;
	t_point	p;
	t_point	p_tile;
	double	angle = engine->data.player.angle;
	double	player_x = engine->data.player.pos.x;
	double	player_y = engine->data.player.pos.y;
	int		center_x = engine->data.screen_size.x / 4;
	int		center_y = engine->data.screen_size.y / 2;

	engine->data.map.size.y = map_rows(engine->data.map.array);
	engine->data.map.size.x = map_max_len(engine->data.map.array);
	tile_size = (engine->data.screen_size.y / engine->data.map.size.y) / 2;
	if (tile_size > (engine->data.screen_size.x / engine->data.map.size.x / 4))
		tile_size = (engine->data.screen_size.x / engine->data.map.size.x) / 4;
	p.y = 0;
	while (p.y < engine->data.map.size.y)
	{
		p.x = 0;
		while (p.x < engine->data.map.size.x)
		{
			double cx = p.x + 0.5;
			double cy = p.y + 0.5;
			double rel_x = (cx - player_x) * tile_size;
			double rel_y = (cy - player_y) * tile_size;
			double rot_x = rel_x * cos(angle - PI / 2) - rel_y * sin(angle - PI / 2);
			double rot_y = rel_x * sin(angle - PI / 2) + rel_y * cos(angle - PI / 2);
			p_tile.x = center_x + (int)rot_x;
			p_tile.y = center_y + (int)rot_y;
			if (engine->data.map.array[p.y][p.x] == '1')
				ft_draw_square(engine, p_tile, tile_size - 2, WHITE);
			else if (engine->data.map.array[p.y][p.x] == '0' ||
					ft_is_charset(engine->data.map.array[p.y][p.x], "SNWE"))
				ft_draw_square(engine, p_tile, tile_size - 2, RED);
			p.x++;
		}
		p.y++;
	}
	draw_centered_triangle(engine, (t_pos){center_x, center_y}, (t_point){10, 10}, YELLOW);
	ft_raycast(engine);
}
