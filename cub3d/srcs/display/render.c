/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:27:53 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/26 14:35:36 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_engine *engine)
{
	double const	current_time = ft_get_time_in_ms();
	static double	last_frame;
	double			delta_time;

	delta_time = 0;
	if (!last_frame)
		last_frame = current_time;
	delta_time = (current_time - last_frame) / 1000;
	if (delta_time >= 0.005)
	{
		ft_render(engine);
		last_frame = current_time;
	}
	return (0);
}

int	ft_render(t_engine *engine)
{
	ft_handle_movement(engine);
	mlx_destroy_image(engine->mlx, engine->data.img.img_ptr);
	engine->data.img.img_ptr = mlx_new_image(engine->mlx,
			engine->data.screen_size.x, engine->data.screen_size.y);
	engine->data.img.addr = mlx_get_data_addr(engine->data.img.img_ptr,
			&engine->data.img.bpp, &engine->data.img.line_len,
			&engine->data.img.endian);
	engine->data.img.h = engine->data.screen_size.y;
	engine->data.img.w = engine->data.screen_size.x;
	ft_draw_map_3d(engine);
	ft_draw_player(engine);
	// ft_draw_map_2d(engine);
	ft_raycast(engine);
	mlx_put_image_to_window(engine->mlx, engine->win, engine->data.img.img_ptr,
		0, 0);
	return (0);
}
