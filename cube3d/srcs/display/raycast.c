/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:40:57 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/25 18:02:52 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

double	ray_distance(t_engine *engine, t_pos ray)
{
	t_pos	p;
	float	res;
	
	p = engine->data.player.pos;
	res = sqrt(pow(ray.x - p.x, 2) + pow(ray.y - p.y, 2));
	return (res);
}

bool	is_wall_ray_v(t_engine *engine, t_pos pos, double angle)
{
	char **map;

	if (cos(angle) < 0)
		pos.x -= 1;
	map = engine->data.map.array;
	if ((int)pos.x < 0 || (int)pos.y < 0 || (int)pos.x > map_max_len(map) || (int)pos.y >= map_rows(map))
		return (true);
	if (map[(int)pos.y][(int)pos.x] == '1' || map[(int)pos.y][(int)pos.x] == ' ')
		return (true);
	return (false);
}

bool	is_wall_ray_h(t_engine *engine, t_pos pos, double angle)
{
	char **map;

	if (sin(angle) > 0)
		pos.y -= 1;
	map = engine->data.map.array;
	if ((int)pos.x < 0 || (int)pos.y < 0 || (int)pos.x > map_max_len(map) || (int)pos.y >= map_rows(map))
		return (true);
	if (map[(int)pos.y][(int)pos.x] == '1' || map[(int)pos.y][(int)pos.x] == ' ')
		return (true);
	return (false);
}

t_pos	horizontal_wall_hit(t_engine *engine, double angle)
{
	t_pos	ray;
	t_pos	player;
	t_pos	step;
	
	player = engine->data.player.pos;
	ft_memset(&ray, 0, sizeof(t_pos));
	if (is_equal(angle, M_PI_2) || is_equal(angle, 3 * M_PI_2))
		return (player);
	if (sin(angle) < 0)
	{
		step.y = 1;
		ray.y = ceil(player.y);
		step.x = step.y / -tan(angle);
		ray.x = player.x + (ray.y - player.y) * step.x;
	}
	if (sin(angle) > 0)
	{
		step.y = -1;
		ray.y = floor(player.y);
		step.x = step.y / -tan(angle);
		ray.x = player.x + (ray.y - player.y) * -step.x;
	}
	if (is_equal(angle, 0) || is_equal(angle, PI))
	{
		step.x = 0;
		ray.x = player.x;
	}
	while (!is_wall_ray_h(engine, ray, angle))
	{
		ray.y += step.y;
		ray.x += step.x;
	}
	return (ray);
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
	}
	if (is_equal(angle, 0) || is_equal(angle, PI))
	{
		step.y = 0;
		ray.y = player.y;
	}
	while (!is_wall_ray_v(engine, ray, angle))
	{
		ray.x += step.x;
		ray.y += step.y;
	}
	return (ray);
}

void	ft_raycast(t_engine *engine)
{
	t_pos	ray_v;
	t_pos	ray_h;
	t_point	start;
	t_point	end;
	double	angle;
	
	angle = engine->data.player.angle - (FOV / 2);
	start.x = engine->data.player.pos.x * engine->data.tile;
	start.y = engine->data.player.pos.y * engine->data.tile;
	while (angle < engine->data.player.angle + FOV / 2)
	{
		ray_v = vertical_wall_hit(engine, angle);
		ray_h = horizontal_wall_hit(engine, angle);
		if (ray_distance(engine, ray_h) < ray_distance(engine, ray_v) && ray_h.x != engine->data.player.pos.x && ray_h.y != engine->data.player.pos.y)
			ray_v = ray_h ;
		end.x = ray_v.x * engine->data.tile;
		end.y = ray_v.y * engine->data.tile;
		ft_draw_line(engine, start, end, BLUE);
		angle += PI / 360;
	}
}
