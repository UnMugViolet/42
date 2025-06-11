/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:27:53 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/11 11:33:39 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_render(t_engine *engine)
{
	t_player	*player;
	t_point		pos;

	player = &engine->data.player;
	pos.x = player->x - (player->image.w / 2);
	pos.y = player->y - (player->image.h / 2);
	mlx_clear_window(engine->mlx, engine->win);
	ft_display_map_2d(engine);
	mlx_put_image_to_window(engine->mlx, engine->win, player->image.img_ptr,
		pos.x, pos.y);
	return (0);
}
