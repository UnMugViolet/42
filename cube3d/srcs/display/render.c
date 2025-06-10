/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:27:53 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/10 11:32:28 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_render(t_engine *engine)
{
	mlx_clear_window(engine->mlx, engine->win);
	ft_put_square(engine, engine->data.player.pos, 10, 0);
	return (0);
}
