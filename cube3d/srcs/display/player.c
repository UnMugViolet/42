/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:17:48 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/10 14:32:56 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_init_player(t_engine *engine)
{
	t_player	*player;

	player = &engine->data.player;
	player->pos.x = engine->data.screen_size.x / 2;
	player->pos.y = engine->data.screen_size.y / 2;
	player->image = ft_draw_square(engine, engine->data.screen_size.y / 20,
			YELLOW);
}
