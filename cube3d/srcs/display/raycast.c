/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:40:57 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/25 16:48:53 by yguinio          ###   ########.fr       */
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

t_pos	ft_hit_wall(t_engine *engine, t_player player)
{
	t_pos	hit_h;
	t_pos	hit_v;
	double	dist_h;
	double	dist_v;

	(void)dist_h;
	(void)hit_h;
	hit_h = ft_cast_horizontal(engine, player);
	hit_v = ft_cast_vertical(engine, player);
	dist_h = ft_distance(hit_h, player.pos);
	dist_v = ft_distance(hit_v, player.pos);
	if (dist_h < dist_v)
		return (hit_h);
	return (hit_v);
}



/*
* Returns the absolute value of the distance the ray has to travel to the next
* grid line using it's direction.
*/
// static double	ft_delta(double ray_direction)
// {
// 	if (ray_direction == 0)
// 		return (1e30);
// 	return (fabs(1 / ray_direction));
// }

/*
* Returns the distance the ray has to travel from its starting point to the next
* grid line.
*/
/* static double	ft_side_dist(double pos, int step, double delta)
{
	double frac;

	frac = pos - floor(pos);
	if (step > 0)
		return ((1.0 - frac) * delta);
	return (frac * delta);
} */

/* t_pos	ft_next_wall(t_engine *engine, t_pos pos, double angle)
{
	t_pos		next;
	t_pos		ray;
	int const	tile_size = engine->data.map.tile_size;
	int dof = -1;
	
	if (angle > PI / 2 && angle < 3 * PI / 2)
	{
		ray.x = floor(pos.x / tile_size) * tile_size - 0.0001f;
		ray.y = pos.y + (pos.x - ray.x) * (tan(angle));
		next.x = -tile_size;
		next.y = tan(angle) * tile_size;
	}
	else if (angle < PI / 2 || angle > 3 * PI / 2)
	{
		ray.x = floor(pos.x / tile_size) * tile_size + tile_size;
		ray.y = pos.y + (pos.x - ray.x) * (tan(angle));
		next.x = tile_size;
		next.y = tan(angle) * tile_size;
	}
	else
	{
		ray.x = pos.x;
		ray.y = pos.y;
		dof = 5;
	}
	
	int map_x, map_y;
	while (++dof < 5)
	{
		map_x = (int)ray.x / tile_size;
		map_y = (int)ray.y / tile_size;

		if (map_x < 0 || map_x >= map_max_len(engine->data.map.array) ||
			map_y < 0 || map_y >= map_rows(engine->data.map.array))
			break ;
		if (engine->data.map.array[map_y][map_x] == '1')
			dof = 5;
		else
		{
			ray.x += next.x;
			ray.y += next.y;
		}
	}
	double distV = sqrt(pow(ray.x - pos.x, 2) + pow(ray.y - pos.y, 2));
	t_pos final;
	final.x = ray.x;
	final.y = ray.y;
	
	dof = -1;
	double atan = -1 / tan(angle);
	if (angle > PI)
	{
		ray.y = floor(pos.y / tile_size) * tile_size - 0.0001f;
		ray.x = pos.x + (pos.y - ray.y) * atan;
		next.y = -tile_size;
		next.x = -next.y * atan;
	}
	else if (angle < PI)
	{
		ray.y = floor(pos.y / tile_size) * tile_size + tile_size;
		ray.x = pos.x + (pos.y - ray.y) * atan;
		next.y = tile_size;
		next.x = -next.y * atan;
	}
	else if (angle == 0 || angle == PI)
	{
		ray.x = pos.x;
		ray.y = pos.y;
		dof = 5;
	}
	
	while (++dof < 5)
	{
		map_x = (int)ray.x / tile_size;
		map_y = (int)ray.y / tile_size;

		if (map_x < 0 || map_x >= map_max_len(engine->data.map.array) ||
			map_y < 0 || map_y >= map_rows(engine->data.map.array))
			break ;
		if (engine->data.map.array[map_y][map_x] == '1')
			dof = 5;
		else
		{
			ray.x += next.x;
			ray.y += next.y;
		}
	}
	double distH = sqrt(pow(ray.x - pos.x, 2) + pow(ray.y - pos.y, 2));
	if (distH < distV)
	{
		final.x = ray.x;
		final.y = ray.y;
	}
	return (final);
} */



/* t_pos	ft_hit_wall(t_engine *engine, t_player player)
{
	t_pos			next_grid;
	t_pos			ray;
	t_pos			res;
	double			min_ray_distance;
	int const		tile = engine->data.map.tile_size;
	double const	angle = engine->data.player.angle;
	int				fov;

	fov = -1;
	ft_memset(&ray, 0, sizeof(t_pos));
	if (angle == 0 || angle == PI)
	{
		ray.x = player.pos.x;
		ray.y = player.pos.y;
		fov = 10;
	}
	else if (angle < PI / 2 || angle > (3 * PI / 2))
	{
		ray.x = ceil(player.pos.x / tile) * tile - 0.0001f;
		next_grid.x = tile ;
		ray.y = player.pos.y + (ray.x - player.pos.x) * tan(angle); //tan(angle) = combien je monte ou descend quand je me déplace de +1;
		next_grid.y = next_grid.x * tan(angle);

	}
	else if (angle > PI / 2 && angle < 3 * PI / 2)
	{
		ray.x = floor(player.pos.x / tile) * tile - 0.0001f;
		next_grid.x = -tile;
		ray.y = player.pos.y + (ray.x - player.pos.x) * tan(angle);
		next_grid.y = next_grid.x * tan(angle);
	}
	while (++fov < 10 && !is_wall_at((const char**)engine->data.map.array, ray.x, ray.y, tile))
	{
		ray.x += next_grid.x;
		ray.y += next_grid.y;
	}
	min_ray_distance = sqrt(pow(ray.x - player.pos.x, 2) + pow(ray.y - player.pos.y, 2));
	res.x = ray.x;
	res.y = ray.y;
	if (angle == PI / 2 || angle == 3 * PI / 2)
	{
		ray.x = player.pos.x;
		ray.y = player.pos.y;
		fov = 10;
	}
	else if (angle > PI && angle < 2 * PI)
	{
		ray.y = ceil(player.pos.y / tile) * tile - 0.0001f;
		next_grid.y = tile;
		ray.x = player.pos.x + (ray.y - player.pos.y) / tan(angle);
		next_grid.x = next_grid.y / tan(angle);
	}
	else if (angle > 0 && angle < PI)
	{
		ray.y = floor(player.pos.y / tile) * tile - 0.0001f;
		next_grid.y = -tile;
		ray.x = player.pos.x + (ray.y - player.pos.y) / tan(angle);
		next_grid.x = next_grid.y / tan(angle);
	}
	while (++fov < 10 && !is_wall_at((const char**)engine->data.map.array, ray.x, ray.y, tile))
	{
		ray.x += next_grid.x;
		ray.y += next_grid.y;
	}
	if (min_ray_distance > sqrt(pow(ray.x - player.pos.x, 2) + pow(ray.y - player.pos.y, 2)))
	{
		res.x = ray.x;
		res.y = ray.y;
	}
	return (res);
} */

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
