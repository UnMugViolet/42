/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:40:57 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/23 10:23:22 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/* static int	sign(double x)
{
	return ((x > 0) - (x < 0));
} */

bool	is_wall_at_ray(const char **map, t_pos ray)
{
	int	map_x;
	int	map_y;
	char	**nik;

	nik = (char **)map;
	map_x = (int)(ray.x);
	map_y = (int)(ray.y);
	if (map_y < 0 || map_x < 0)
		return (true);
	if (map_y >= map_rows(nik))
		return (true);
	if (map_x >= (int)ft_strlen(map[map_y]))
		return (true);
	if (map[map_y][map_x] == '1')
		return (true);
	return (false);
}

bool	is_equal(double a, double b)
{
	return (fabs(a - b) < EPSILON);
}

static double	ft_distance(t_pos a, t_pos b)
{
	double	x;
	double	y;

	x = a.x - b.x;
	y = a.y - b.y;
	return (sqrt(x * x + y * y));
}

static t_pos	ft_cast_horizontal(t_engine *e, t_player p)
{
	t_pos		ray;
	t_pos		step;
	double		angle;
	int			i;
	t_pos		*player;
	
	player = &p.pos;
	angle = e->data.player.angle;
	i = 0;
	if (is_equal(angle, PI / 2) || is_equal(angle, 3 * PI / 2))
		return (*player);
	if (cos(angle) > 0)
	{
	    ray.x = ceil(p.pos.x) + EPSILON;
	    step.x = 1;
	}
	else
	{
	    ray.x = floor(p.pos.x) - EPSILON;
	    step.x = -1;
	}
	step.y = 1 * tan(angle);
	ray.y = player->x + step.y * fabs(ray.x - player->x);
	while (i < 10 && !is_wall_at_ray((const char **)e->data.map.array, ray))
	{
		ray.x += step.x;
		ray.y += step.y;
		if (ray.y > map_max_len(e->data.map.array))
			ray.y = map_max_len(e->data.map.array) - EPSILON;
		i++;
	}
	return (ray);
}

static t_pos	ft_cast_vertical(t_engine *e, t_player p)
{
	t_pos		ray;
	t_pos		step;
	double		angle;
	int			i;
	t_pos		*player;
	
	player = &p.pos;
	angle = e->data.player.angle;
	i = 0;
	if (is_equal(angle, 0) || is_equal(angle, PI))
		return (*player);
	if (sin(angle) > 0)
	{
	    ray.y = floor(p.pos.y) - EPSILON;
	    step.y = -1;
	}
	else
	{
	    ray.y = ceil(p.pos.y) + EPSILON;
	    step.y = 1;
	}
	step.x = 1 / tan(angle);
	ray.x = player->x + step.x * fabs(ray.y - player->y);
	while (i < 10 && !is_wall_at_ray((const char **)e->data.map.array, ray))
	{
		ray.y += step.y;
		ray.x += step.x;
		if (ray.x > map_max_len(e->data.map.array))
			ray.x = map_max_len(e->data.map.array) - EPSILON;
		i++;
	}
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
	int const		tile = engine->data.map.tile_size;
	// double const	start_angle = engine->data.player.angle - (FOV / 2);
	// double const	angle_step = FOV / NUM_RAYS;
	int				ray_i;
	t_pos			hit_pos;
	// t_point			start;
	// t_point			end;
	// double			player_x = engine->data.player.pos.x;
	// double			player_y = engine->data.player.pos.y;
	// int				center_x = engine->data.screen_size.x / 4;
	// int				center_y = engine->data.screen_size.y / 2;

	// start.x = center_x;
	// start.y = center_y;

	ray_i = 0;
	while (ray_i < NUM_RAYS)
	{
		// double ray_angle = start_angle + ray_i * angle_step;
		

		// Calcul du point d'impact du rayon dans le monde
		hit_pos = ft_hit_wall(engine, engine->data.player);

		// Calcul des coordonnées relatives au joueur
		// double rel_x = hit_pos.x - player_x;
		// double rel_y = hit_pos.y - player_y;

		// // Rotation inverse (pour que le joueur regarde toujours vers le haut)
		// double cos_a = cos(-engine->data.player.angle - PI / 2);
		// double sin_a = sin(-engine->data.player.angle - PI / 2);
		// double rot_x = rel_x * cos_a - rel_y * sin_a;
		// double rot_y = rel_x * sin_a + rel_y * cos_a;

		// // Conversion en pixels pour la minimap
		// end.x = center_x + rot_x * tile / 2;
		// end.y = center_y + rot_y * tile / 2;

		// Trace du rayon depuis le centre fixe du joueur
		// ft_draw_line(engine, start, end, BLUE);
		t_point start, end;
		start.x = engine->data.player.pos.x * tile;
		start.y = engine->data.player.pos.y * tile;
		end.x = hit_pos.x * tile;
		end.y = hit_pos.y * tile;
		ft_draw_line(engine,start, end, YELLOW);

		ray_i++;
	}
}
