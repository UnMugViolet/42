/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:40:57 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/18 17:40:57 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_raycast(t_engine *engine)
{
    int const		tile = engine->data.map.tile_size;
    double const	start_angle = engine->data.player.angle - (FOV / 2) + M_PI_2;
    double const	angle_step = FOV / NUM_RAYS;
    int				ray_i;
    t_pos			ray;
    t_point			start;
    t_point			end;

    int center_x = engine->data.screen_size.x / 4;
    int center_y = engine->data.screen_size.y / 2;
    double player_x = engine->data.player.pos.x;
    double player_y = engine->data.player.pos.y;
    double angle = engine->data.player.angle;

    ray_i = 0;
    while (ray_i < NUM_RAYS)
    {
        double ray_angle = start_angle + ray_i * angle_step;
        ray.x = player_x;
        ray.y = player_y;
        t_pos ray_pos;
        while (1)
        {
            ray_pos.x = ray.x;
            ray_pos.y = ray.y;
            if (is_wall((const char **)engine->data.map.array, ray_pos, tile))
                break ;
            ray.x += cos(ray_angle) * 0.05;
            ray.y += sin(ray_angle) * 0.05;
        }

        double rel_x = (ray.x - player_x) * tile;
        double rel_y = (ray.y - player_y) * tile;
        double rot_x = rel_x * cos(angle - M_PI_2) - rel_y * sin(angle - M_PI_2);
		double rot_y = rel_x * sin(angle - M_PI_2) + rel_y * cos(angle - M_PI_2);

        start.x = center_x;
        start.y = center_y;
        end.x = center_x + (int)rot_x;
        end.y = center_y + (int)rot_y;
        ft_draw_line(engine, start, end, BLUE);

        ray_i++;
    }
}