/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:40:57 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/26 15:15:24 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_wall_ray_v(t_engine *engine, t_pos pos, double angle)
{
	char	**map;

	if (cos(angle) < 0)
		pos.x -= 1;
	map = engine->data.map.array;
	if ((int)pos.x < 0 || (int)pos.y < 0 || (int)pos.x > map_max_len(map)
		|| (int)pos.y >= map_rows(map))
		return (true);
	if (map[(int)pos.y][(int)pos.x] == '1'
		|| map[(int)pos.y][(int)pos.x] == ' ')
		return (true);
	return (false);
}

bool	is_wall_ray_h(t_engine *engine, t_pos pos, double angle)
{
	char	**map;

	if (sin(angle) > 0)
		pos.y -= 1;
	map = engine->data.map.array;
	if ((int)pos.x < 0 || (int)pos.y < 0 || (int)pos.x > map_max_len(map)
		|| (int)pos.y >= map_rows(map))
		return (true);
	if (map[(int)pos.y][(int)pos.x] == '1'
		|| map[(int)pos.y][(int)pos.x] == ' ')
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
	ft_check_horizontal_angle(angle, player, &ray, &step);
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
	ft_check_vertical_angle(angle, player, &ray, &step);
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
	t_pos	util;
	t_pos	ray_len;

	util.y = 0;
	util.x = engine->data.player.angle - (FOV / 2);
	start.x = engine->data.player.pos.x * engine->data.tile;
	start.y = engine->data.player.pos.y * engine->data.tile;
	while (util.y < NUM_RAYS)
	{
		ray_v = vertical_wall_hit(engine, util.x);
		ray_h = horizontal_wall_hit(engine, util.x);
		ray_len.x = ray_distance(engine, ray_h);
		ray_len.y = ray_distance(engine, ray_v);
		if (ray_len.x < ray_len.y && ray_h.x != engine->data.player.pos.x
			&& ray_h.y != engine->data.player.pos.y)
		{
			ft_display_wall(engine, util.y, ray_len.x, util.x);
			end.x = ray_h.x * engine->data.tile;
			end.y = ray_h.y * engine->data.tile;
		}
		else
		{
			ft_display_wall(engine, util.y, ray_len.y, util.x);
			end.x = ray_v.x * engine->data.tile;
			end.y = ray_v.y * engine->data.tile;
		}
		if ((int)util.y % 50 == 0)
			ft_draw_line(engine, start, end, BLUE);
		util.x += FOV / NUM_RAYS;
		util.y++;
	}
}
