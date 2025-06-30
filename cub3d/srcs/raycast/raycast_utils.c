/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:06:13 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/30 15:27:38 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_vertical_angle(double angle, t_pos player, t_pos *ray, \
		t_pos *step)
{
	if (cos(angle) > 0)
	{
		step->x = 1;
		ray->x = ceil(player.x);
		step->y = step->x * -tan(angle);
		ray->y = player.y + (ray->x - player.x) * step->y;
	}
	if (cos(angle) < 0)
	{
		step->x = -1;
		ray->x = floor(player.x);
		step->y = step->x * -tan(angle);
		ray->y = player.y + (ray->x - player.x) * -step->y;
	}
	if (is_equal(angle, 0) || is_equal(angle, PI))
	{
		step->y = 0;
		ray->y = player.y;
	}
}

void	ft_check_horizontal_angle(double angle, t_pos player, t_pos *ray, \
		t_pos *step)
{
	if (sin(angle) < 0)
	{
		step->y = 1;
		ray->y = ceil(player.y);
		step->x = step->y / -tan(angle);
		ray->x = player.x + (ray->y - player.y) * step->x;
	}
	if (sin(angle) > 0)
	{
		step->y = -1;
		ray->y = floor(player.y);
		step->x = step->y / -tan(angle);
		ray->x = player.x + (ray->y - player.y) * -step->x;
	}
	if (is_equal(angle, 0) || is_equal(angle, PI))
	{
		step->x = 0;
		ray->x = player.x;
	}
}

double	ray_distance(t_engine *engine, t_pos ray)
{
	t_pos	p;
	float	res;

	p = engine->data.player.pos;
	res = sqrt(pow(ray.x - p.x, 2) + pow(ray.y - p.y, 2));
	return (res);
}

void	ft_select_shortest_ray(t_player *p, t_ray *ray, t_ray *temp)
{
	if (ray->len < temp->len && ray->hit.x != p->pos.x
		&& ray->hit.y != p->pos.y)
	{
		ray->end.x = ray->hit.x * tile(NULL);
		ray->end.y = ray->hit.y * tile(NULL);
		ray->is_vertical = false;
	}
	else
	{
		ft_copy_ray(ray, temp);
		ray->end.x = temp->hit.x * tile(NULL);
		ray->end.y = temp->hit.y * tile(NULL);
		ray->is_vertical = true;
	}
}
