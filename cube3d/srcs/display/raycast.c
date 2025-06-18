/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:40:57 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/18 15:57:28 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_raycast(t_engine *engine)
{
	int const		tile = engine->data.map.tile_size;
	double const	start_angle = engine->data.player.angle - (FOV / 2);
	double const	angle_step = FOV / NUM_RAYS;
	int				ray_i;
	t_pos			ray;
	t_point			start;
	t_point			end;

	ray_i = 0;
	while (ray_i++ < NUM_RAYS)
	{
		ray.x = engine->data.player.pos.x;
		ray.y = engine->data.player.pos.y;
		t_pos ray_pos;
		while (1)
		{
			ray_pos.x = ray.x;
			ray_pos.y = ray.y;
			if (is_wall((const char **)engine->data.map.array, ray_pos, tile))
				break ;
			ray.x += cos(start_angle + ray_i * angle_step) * 0.05;
			ray.y += sin(start_angle + ray_i * angle_step) * 0.05;
		}
		start.x = (int)(engine->data.player.pos.x * tile);
		start.y = (int)(engine->data.player.pos.y * tile);
		end.x = (int)(ray.x * tile);
		end.y = (int)(ray.y * tile);
		ft_draw_line(engine, start, end, BLUE);
	}
}
