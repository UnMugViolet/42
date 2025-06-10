/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:27:53 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/10 14:25:20 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_render(t_engine *engine)
{
	t_player	*player;
	t_point		pos;			

	player = &engine->data.player;
	pos.x = player->pos.x - (player->image.w / 2);
	pos.y = player->pos.y - (player->image.h / 2);
	mlx_clear_window(engine->mlx, engine->win);
	mlx_put_image_to_window(engine->mlx, engine->win, player->image.img_ptr, pos.x, pos.y);
	return (0);
}
