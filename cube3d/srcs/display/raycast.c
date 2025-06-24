/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:40:57 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/24 16:04:10 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_pos	ft_delta(t_engine *engine)
{
	t_pos	res;

	res.x = 1 / fabs(cos(engine->data.player.angle));
	res.y = 1 / fabs(sin(engine->data.player.angle));
	return (res);
}

double	ft_get_ray_len(t_pos start, t_pos end)
{
	return (sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2)));
}

t_pos	ft_intersect_vertical(t_engine *engine, t_pos pos)
{
	t_pos	next;
	t_pos	step;

	if (is_equal(engine->data.player.angle, M_PI_2) || is_equal(engine->data.player.angle, 3 * M_PI_2))
		return ((t_pos){1 / EPSILON, pos.y});
	if (cos(engine->data.player.angle) > 0)
	{
		step.x = 1;
		next.x = floor(pos.x) + 1;
	}
	else
	{
		step.x = -1;
		next.x = floor(pos.x) - EPSILON;
	}
	next.y = pos.y + (next.x - pos.x) * tan(engine->data.player.angle);
	step.y = step.x * tan(engine->data.player.angle);
	while (!is_wall(engine, next, 0))
	{
		next.x += step.x;
		next.y += step.y;
	}
	return (next);
}

t_pos	ft_intersect_horizontal(t_engine *engine, t_pos pos)
{
	t_pos	next;
	t_pos	step;
	
	if (is_equal(engine->data.player.angle, 0) || is_equal(engine->data.player.angle, PI))
		return ((t_pos){1 / EPSILON, pos.y});
	if (sin(engine->data.player.angle) > 0)
	{
		step.y = -1;
		next.y = floor(pos.y) - EPSILON;
	}
	if (sin(engine->data.player.angle) < 0)
	{
		step.y = 1;
		next.y = ceil(pos.y) - EPSILON;
	}
	next.x = pos.x + (next.y - pos.y) / tan(engine->data.player.angle);
	step.x = step.y / tan(engine->data.player.angle);
	while (!is_wall(engine, next, 10))
	{
		next.x += step.x;
		next.y += step.y;
	}
	return (next);
}

void	ft_raycast(t_engine *engine)
{
	int				ray_i;
	t_point			start;
	t_point			end_point;
	t_player		*player;
	t_pos			inter_h;
	t_pos			inter_v;
	double			ray_len_h;
	double			ray_len_v;
	double			ray_len;

	player = &engine->data.player;    
	ray_i = 0;
	while (ray_i < NUM_RAYS)
	{
		start.x = player->pos.x * engine->data.tile;
		start.y = player->pos.y * engine->data.tile;

		// Calculate horizontal and vertical intersections
		inter_h = ft_intersect_horizontal(engine, player->pos);
		inter_v = ft_intersect_vertical(engine, player->pos);

		// Get ray distances
		ray_len_h = ft_get_ray_len(player->pos, inter_h);
		ray_len_v = ft_get_ray_len(player->pos, inter_v);

		// Choose shortest ray (hit first wall)
		if (ray_len_v < ray_len_h)
			ray_len = ray_len_v;
		else
			ray_len = ray_len_h;

		// Compute the end point using ray direction and pixel scaling
		end_point.x = start.x + cos(player->angle) * ray_len * engine->data.tile;
		end_point.y = start.y - sin(player->angle) * ray_len * engine->data.tile;

		// Draw line (rail) from player to wall
		ft_draw_line(engine, start, end_point, BLUE);
		ray_i++;
	}
	printf("\rangle : %f ray len hor : %f, ray len vert : %f, end_point x :  %d, end_point y : %d", engine->data.player.angle, ray_len_h, ray_len_v, end_point.x, end_point.y);

}

/*  void	ft_raycast(t_engine *engine)
{
    int				ray_i;
    t_point			start;
    t_pos			end;
    t_point         end_point;
    t_player		*player;
	t_pos			delta;
	t_pos			side_dist;
	t_point 		step;
	bool			hit;
	t_point			map_coord;
	int				side;
	float			distance;
	
	hit = false;
	delta = ft_delta(engine);
	player = &engine->data.player;
	map_coord.x = (int)player->pos.x;
	map_coord.y = (int)player->pos.y;
    ray_i = 0;
    while (ray_i < NUM_RAYS)
    {
        
        start.x = player->pos.x * engine->data.tile;
        start.y = player->pos.y * engine->data.tile;
        end.y = engine->data.player.pos.y;
        end.x = engine->data.player.pos.x;
		if (engine->data.player.dir.x < 0)
		{
			step.x = -1;
			side_dist.x = (player->pos.x - map_coord.x) * delta.x;
		}
		else
		{
			step.x = 1;
			side_dist.x = (map_coord.x + 1 - player->pos.x) * delta.x;
		}
		if (-engine->data.player.dir.y < 0)
		{
			step.y = -1;
			side_dist.y = (player->pos.y - map_coord.y) * delta.y;
		}
		else
		{
			step.y = 1;
			side_dist.y = (map_coord.y + 1 - player->pos.y) * delta.y;
		}
		while (hit == 0)
		{
			if (side_dist.x < side_dist.y)
			{
				side_dist.x += delta.x;
				map_coord.x += step.x;
				side = 0; // côté X
			}
			else
			{
				side_dist.y += delta.y;
				map_coord.y += step.y;
				side = 1; // côté Y
			}
			if (engine->data.map.array[map_coord.y][map_coord.x] == '1')
				hit = 1;
		}
		if (side == 0)
			distance = fabs((map_coord.x - player->pos.x + (1 - step.x) / 2) / engine->data.player.dir.x);
		else
			distance = fabs((map_coord.y - player->pos.y + (1 - step.y) / 2) / engine->data.player.dir.y);
		end_point.x = distance * cos(player->angle);
		end_point.y = distance * -sin(player->angle);
		printf("\r point.x = %f point.y = %f", (float)map_coord.x - player->pos.x, (float)map_coord.y - player->pos.y);
		ft_draw_line(engine, start, end_point, BLUE);
        ray_i++;
    }
} */