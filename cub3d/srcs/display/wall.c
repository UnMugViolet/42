/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:18:09 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/26 15:10:37 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_display_wall(t_engine *engine, int v_pxl, double ray_len, double angle)
{
	int				height;
	double const	correction_factor = cos(angle - engine->data.player.angle);
	t_point			start;
	t_point			end;

	height = WIN_H / ((ray_len * correction_factor) * 0.5);
	start.x = WIN_W - v_pxl;
	end.x = WIN_W - v_pxl;
	start.y = WIN_H / 2 - height / 2;
	if (start.y < 0)
		start.y = 0;
	end.y = WIN_H / 2 + height / 2;
	if (end.y > WIN_H)
		end.y = WIN_H;
	ft_draw_line(engine, start, end, YELLOW);
}
