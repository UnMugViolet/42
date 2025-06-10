/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:45:52 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/10 11:07:03 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_put_square(t_engine *engine, t_point point, int wideness, int color)
{
	t_point	p;

	if (!color)
		color = YELLOW;
	p.y = point.y - (wideness / 2);
	while (p.y < point.y + (wideness / 2))
	{
		p.x = point.x - (wideness / 2);
		while (p.x < point.x + (wideness / 2))
		{
			mlx_pixel_put(engine->mlx, engine->win, p.x, p.y, color);
			p.x++;
		}
		p.y++;
	}
}
