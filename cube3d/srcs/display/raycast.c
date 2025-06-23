/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:40:57 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/23 19:06:19 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

double	ft_get_ray_len(t_pos start, t_pos end)
{
	return (sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2)));
}

t_pos	ft_intersect_vertical(t_engine *engine, t_pos pos)
{
	t_pos	next;
	t_pos	step;
	
	if (is_equal(engine->data.player.angle, M_PI_2) || is_equal(engine->data.player.angle, 3 * M_PI_2))
		return ((t_pos){1 / EPSILON, 1 / EPSILON});
	if (cos(engine->data.player.angle) > 0)
	{
		step.y = 1;
		next.y = ceil(pos.y);
	}
	if (cos(engine->data.player.angle) < 0)
	{
		step.y = -1;
		next.y = floor(pos.y);
	}
	next.x = pos.x + (next.y - pos.y) * tan(engine->data.player.angle);
	step.x = step.y * tan(engine->data.player.angle);
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
	
	if (is_equal(engine->data.player.angle, 0) || is_equal(engine->data.player.angle, M_PI_2))
		return ((t_pos){1 / EPSILON, 1 / EPSILON});
	if (sin(engine->data.player.angle) > 0)
	{
		step.y = -1;
		next.y = floor(pos.y);
	}
	if (sin(engine->data.player.angle) < 0)
	{
		step.y = 1;
		next.y = ceil(pos.y);
	}
	next.x = pos.x + (next.y - pos.y) / tan(engine->data.player.angle);
	step.x = step.y / tan(engine->data.player.angle);
	while (!is_wall(engine, next, 0))
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
    t_pos			end;
    t_pos			end_point;
	t_player		*player;
	double			ray_len;
	
	player = &engine->data.player;    
    ray_i = 0;
    while (ray_i < NUM_RAYS)
    {
        start.x = engine->data.screen_size.x / 4;
        start.y = engine->data.screen_size.y / 2;
		ray_len = ft_get_ray_len(player->pos, ft_intersect_horizontal(engine, player->pos));
        if (ray_len <= ft_get_ray_len(player->pos, ft_intersect_vertical(engine, player->pos)))
		{
			end.x = ft_intersect_vertical(engine, player->pos).x;
			end.y = ft_intersect_vertical(engine, player->pos).y;
		}
		else
		{
			end.x = ft_intersect_horizontal(engine, player->pos).x;
			end.y = ft_intersect_horizontal(engine, player->pos).y;
		}
        end_point.x = start.x;
        end_point.y = (start.y - sqrt(pow(end.x - player->pos.x, 2) + pow(end.y - player->pos.y, 2)) * engine->data.tile / (PI / 2));
        ft_draw_line(engine, start, (t_point){end_point.x, end_point.y}, BLUE);
        ray_i++;
    }
}
