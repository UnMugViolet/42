/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:26:32 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/06/25 16:31:57 by yguinio          ###   ########.fr       */
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
				ft_draw_square(engine, (t_point){(j + 0.5) * engine->data.tile,  (i + 0.5) * engine->data.tile}, engine->data.tile - 1, WHITE);
			else if (engine->data.map.array[i][j] != ' ')
				ft_draw_square(engine, (t_point){(j + 0.5) * engine->data.tile,  (i + 0.5) * engine->data.tile}, engine->data.tile  - 1, RED);
		}
	}
}
