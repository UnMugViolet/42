/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:40:57 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/30 14:47:01 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_wall_ray_v(t_engine *engine, t_pos pos, double angle)
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

static bool	is_wall_ray_h(t_engine *engine, t_pos pos, double angle)
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
	t_ray			ray;
	t_ray			ray_temp;
	t_pos			util;
	t_player const	p = engine->data.player;

	ft_set_t_pos(&util, p.angle - (FOV / 2), 0);
	ft_set_t_point(&ray.start, p.pos.x * tile(NULL), p.pos.y * tile(NULL));
	while (util.y < NUM_RAYS)
	{
		ft_set_rays(engine, &ray, &ray_temp, util.x);
		if (ray.len < ray_temp.len && ray.hit.x != p.pos.x
			&& ray.hit.y != p.pos.y)
		{
			ray.end.x = ray.hit.x * tile(NULL);
			ray.end.y = ray.hit.y * tile(NULL);
			ray.is_vertical = false;
		}
		else
		{
			ft_copy_ray(&ray, &ray_temp);
			ray.end.x = ray_temp.hit.x * tile(NULL);
			ray.end.y = ray_temp.hit.y * tile(NULL);
			ray.is_vertical = true;
		}
		ft_display_wall(engine, util.y, ray.len, util.x, ray.hit, ray.is_vertical);
		engine->data.ray[(int)util.y] = ray;
		util.x += FOV / NUM_RAYS;
		util.y++;
	}
}
