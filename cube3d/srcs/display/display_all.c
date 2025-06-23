/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:24:26 by yguinio           #+#    #+#             */
/*   Updated: 2025/06/20 10:49:45 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_draw_map_2d(t_engine *engine)
{
	int	i;
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
	}
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
}
