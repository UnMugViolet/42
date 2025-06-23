/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:40:57 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/23 16:21:19 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_raycast(t_engine *engine)
{
    int const		tile = engine->data.map.tile_size;
    int				ray_i;
    t_point			start;
    t_pos			end;
    t_point         end_point;
    
    double angle = engine->data.player.angle;

    ray_i = 0;
    while (ray_i < NUM_RAYS)
    {
        
        start.x = engine->data.screen_size.x / 4;
        start.y = engine->data.screen_size.y / 2;
        end.y = engine->data.player.pos.y;
        end.x = engine->data.player.pos.x;
        while (!is_wall((const char **)engine->data.map.array, end, tile))
        {
            end.x += cos(angle) * 0.5;
            end.y += sin(angle) * 0.5;
        }
        end_point.x = start.x;
        end_point.y = start.y - sqrt(pow(engine->data.player.pos.x end.x + , 2) + pow(end.y + engine->data.player.pos.y, 2));
        ft_draw_line(engine, start, end_point, BLUE);
        printf("\rangle: %f, end.y: %f", angle, sqrt(pow(end.x + engine->data.player.pos.x, 2) + pow(end.y + engine->data.player.pos.y, 2)));
        ray_i++;
    }
}
