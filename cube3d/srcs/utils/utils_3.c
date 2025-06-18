/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:11:26 by yguinio           #+#    #+#             */
/*   Updated: 2025/06/18 14:01:38 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_draw_rectangle(t_engine *engine, t_point start, t_point end, int color)
{
	int	temp;

	temp = start.x;
	while (start.y < end.y)
	{
		start.x = temp;
		while (start.x < end.x)
		{
			ft_put_pixel(engine, start, color);
			start.x++;
		}
		start.y++;
	}
}

void	ft_draw_map_3d(t_engine *engine)
{
	ft_draw_rectangle(engine, (t_point){engine->data.screen_size.x / 2, 0}, (t_point){engine->data.screen_size.x, engine->data.screen_size.y / 2}, engine->data.map.colors[0]);
	ft_draw_rectangle(engine, (t_point){engine->data.screen_size.x / 2, engine->data.screen_size.y / 2}, (t_point){engine->data.screen_size.x, engine->data.screen_size.y}, engine->data.map.colors[1]);
}

void	ft_angle_to_dir(double angle, t_pos *dir)
{
	dir->x = cos(angle);
	dir->y = sin(angle);
}
