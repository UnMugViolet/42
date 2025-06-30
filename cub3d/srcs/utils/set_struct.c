/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:33:35 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/30 14:19:53 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_t_point(t_point *p, int x, int y)
{
	p->x = x;
	p->y = y;
}

void	ft_set_t_pos(t_pos *p, double x, double y)
{
	p->x = x;
	p->y = y;
}

void	ft_set_ray(t_ray *ray, double *angle, t_point *end, t_pos *hit)
{
	if (angle)
		ray->angle = *angle;
	if (end)
		ray->end = *end;
	if (hit)
		ray->hit = *hit;
}

void	ft_set_rays(t_engine *engine, t_ray *ray, t_ray *ray_temp, double angle)
{
	ray_temp->hit = vertical_wall_hit(engine, angle);
	ray_temp->len = ray_distance(engine, ray_temp->hit);
	ray->hit = horizontal_wall_hit(engine, angle);
	ray->len = ray_distance(engine, ray->hit);
}

void	ft_copy_ray(t_ray *paste, t_ray *copy)
{
	if (paste && copy)
	{
		paste->angle = copy->angle;
		paste->end = copy->end;
		paste->hit = copy->hit;
		paste->len = copy->len;
	}
}
