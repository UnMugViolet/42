/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:17:48 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/24 16:53:56 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_clear_player(t_engine *engine)
{
	int		tile;
	t_point	center;

	tile = engine->data.map.tile_size;
	center.x = (int)(engine->data.player.pos.x * tile);
	center.y = (int)(engine->data.player.pos.y * tile);
	ft_draw_square(engine, (t_point){center.x, center.y},
		engine->data.player.size, BLACK);
}

void	ft_draw_player(t_engine *engine)
{
	int		tile;
	t_point	center;
	t_point	end;

	tile = engine->data.map.tile_size;
	center.x = (int)(engine->data.player.pos.x * tile) - tile / 2;
	center.y = (int)(engine->data.player.pos.y * tile) - tile / 2;
	ft_draw_square(engine, (t_point){center.x, center.y},
		engine->data.player.size, YELLOW);
	end.x = center.x + cos(engine->data.player.angle) * (tile);
	end.y = center.y - sin(engine->data.player.angle) * (tile);
	// ft_draw_line(engine, center, end, BLACK);
	t_pos temp = ft_hit_wall(engine, engine->data.player);
	end.x = temp.x * tile - tile / 2;
	end.y = temp.y * tile - tile / 2;
	ft_draw_line(engine, center, end, BLUE);
	printf("\rAngle : %f | Player pos x :%f y :%f Next hit at x :%f y:%f", engine->data.player.angle, engine->data.player.pos.x, engine->data.player.pos.y, temp.x, temp.y);
}

void	draw_centered_triangle(t_engine *engine, t_pos pos, t_point dimension,
		int color)
{
	t_point		p;
	int			x_min;
	int			x_max;
	float const	half_w = dimension.y / 2.0f;
	float		ratio;

	p.y = 0;
	while (p.y < dimension.x)
	{
		ratio = 1.0f - (float)p.y / (float)dimension.x;
		x_min = (int)(-half_w * ratio);
		x_max = (int)(half_w * ratio);
		p.x = x_min;
		while (p.x <= x_max)
		{
			ft_put_pixel(engine, (t_point){pos.x + p.x, pos.y + dimension.x / 2
				- p.y}, color);
			p.x++;
		}
		p.y++;
	}
}
