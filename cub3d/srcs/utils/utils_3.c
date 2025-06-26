/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:11:26 by yguinio           #+#    #+#             */
/*   Updated: 2025/06/26 11:56:11 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_rectangle(t_engine *engine, t_point start, t_point end, \
			int color)
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
	t_point	screen;

	screen = engine->data.screen_size;
	ft_draw_rectangle(engine, (t_point){0, 0}, \
			(t_point){screen.x, screen.y / 2}, engine->data.map.colors[0]);
	ft_draw_rectangle(engine, (t_point){0, screen.y / 2}, \
			(t_point){screen.x, screen.y}, engine->data.map.colors[1]);
}

void	ft_angle_to_dir(double angle, t_pos *dir)
{
	dir->x = cos(angle);
	dir->y = sin(angle);
}

bool	is_equal(double a, double b)
{
	return (fabs(a - b) < EPSILON);
}
