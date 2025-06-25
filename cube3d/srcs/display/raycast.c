/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:40:57 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/25 16:53:57 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	is_wall_ray(t_engine *engine, t_pos pos, double angle)
{
	char **map;

	(void)angle;
	if (cos(angle) < 0)
		pos.x -= 1;
	map = engine->data.map.array;
	if ((int)pos.x < 0 || (int)pos.y < 0 || (int)pos.x > map_max_len(map) || (int)pos.y >= map_rows(map))
		return (true);
	if (map[(int)pos.y][(int)pos.x] == '1' || map[(int)pos.y][(int)pos.x] == ' ')
		return (true);
	return (false);
}

t_pos	vertical_wall_hit(t_engine *engine, double angle)
{
	t_pos	ray;
	t_pos	player;
	t_pos	step;
	
	player = engine->data.player.pos;
	ft_memset(&ray, 0, sizeof(t_pos));
	if (is_equal(angle, M_PI_2) || is_equal(angle, 3 * M_PI_2))
		return (player);
	if (cos(angle) > 0)
	{
		step.x = 1;
		ray.x = ceil(player.x);
		step.y = step.x * -tan(angle);
		ray.y = player.y + (ray.x - player.x) * step.y;
	}
	if (cos(angle) < 0)
	{
		step.x = -1;
		ray.x = floor(player.x);
		step.y = step.x * -tan(angle);
		ray.y = player.y + (ray.x - player.x) * -step.y;
		// printf("ray.x = %f, ray.y = %f, step = %f\n", ray.x, ray.y, step.y);
	}
	if (is_equal(angle, 0) || is_equal(angle, PI))
	{
		step.y = 0;
		ray.y = player.y;
	}
	while (!is_wall_ray(engine, ray, angle))
	{
		ray.x += step.x;
		ray.y += step.y;
	}
	// if (cos(angle) < 0)
	// 	ray.x++;
	printf("FINAL ray.x = %f, ray.y = %f\n", ray.x, ray.y);
	return (ray);
}

void	ft_raycast(t_engine *engine)
{
	t_pos	ray;
	t_point	start;
	t_point	end;

	start.x = engine->data.player.pos.x * engine->data.tile;
	start.y = engine->data.player.pos.y * engine->data.tile;
	end.x = (engine->data.player.pos.x + cos(engine->data.player.angle)) * engine->data.tile;
	end.y = (engine->data.player.pos.y - sin(engine->data.player.angle)) * engine->data.tile;
	ft_draw_line(engine, start, end, BLACK);
	ray = vertical_wall_hit(engine, engine->data.player.angle);
	if (ray.x == engine->data.player.pos.x && ray.y == engine->data.player.pos.y)
		return ;
	end.x = ray.x * engine->data.tile;
	end.y = ray.y * engine->data.tile;
	printf("DRAWN ray.x = %f, ray.y = %f\n", (float)end.x / engine->data.tile, (float)end.y / engine->data.tile);
	// printf("angle : %f, ray x : %f, ray Y :%f\n", engine->data.player.angle, ray.x, ray.y);
	ft_draw_line(engine, start, end, BLUE);
}
