/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:26:32 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/06/30 15:20:07 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_map_2d(t_engine *engine)
{
	int	i;
	int	j;
	int	tile;

	i = -1;
	tile = engine->data.tile;
	while (++i < map_rows(engine->data.map.array))
	{
		j = -1;
		while (++j < map_max_len(engine->data.map.array))
		{
			if (engine->data.map.array[i][j] == '1')
				ft_draw_square(engine, (t_point){(j + 0.5) * tile, (i + 0.5) \
					* tile}, tile, BLACK);
			else if (engine->data.map.array[i][j] != ' ')
				ft_draw_square(engine, (t_point){(j + 0.5) * tile, (i + 0.5) \
					* tile}, tile, RED);
		}
	}
	i = -1;
	while (++i < WIN_W)
		ft_draw_line(engine, engine->data.ray[i].start,
			engine->data.ray[i].end, BLUE);
}

/* void	ft_draw_map_2d_move(t_engine *engine)
{
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
}
 */
