/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:45:52 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/13 10:23:39 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

size_t	ft_get_time_in_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_putstr_fd("Error: gettimeofday()\n", 2);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000));
}

t_img	ft_draw_square(t_engine *engine, int wideness, int color)
{
	int		pixel;
	t_img	image;

	image.img_ptr = mlx_new_image(engine->mlx, wideness, wideness);
	image.addr = mlx_get_data_addr(image.img_ptr, &image.bpp, &image.line_len,
			&image.endian);
	image.h = 0;
	while (image.h < wideness - 1)
	{
		image.w = 0;
		while (image.w + 1 < wideness)
		{
			pixel = (image.h * image.line_len) + (image.w * 4);
			image.addr[pixel + 0] = (color) & 0xFF;
			image.addr[pixel + 1] = (color >> 8) & 0xFF;
			image.addr[pixel + 2] = (color >> 16) & 0xFF;
			image.addr[pixel + 3] = (color >> 24) & 0xFF;
			image.w++;
		}
		image.h++;
	}
	return (image);
}

void	ft_display_map_2d(t_engine *engine)
{
	int		tile_size;
	t_point	p;

	engine->data.map.size.y = map_rows(engine->data.map.array);
	engine->data.map.size.x = map_max_len(engine->data.map.array);
	// tile_size = engine->data.screen_size.y / engine->data.map.size.y;
	tile_size = 32;
	if (tile_size > engine->data.screen_size.x / engine->data.map.size.x)
		tile_size = engine->data.screen_size.x / engine->data.map.size.x;
	p.y = 0;
	while (p.y < engine->data.map.size.y)
	{
		p.x = 0;
		while (p.x < engine->data.map.size.x)
		{
			if (engine->data.map.array[p.y][p.x] == '1')
			{
				mlx_put_image_to_window(engine->mlx, engine->win,
					engine->data.map.wall.img_ptr,
					p.x * tile_size, p.y * tile_size);
			}
			p.x++;
		}
		p.y++;
	}
}

t_img	ft_draw_line(t_engine *engine, int lenght, int color)
{
	int		pixel;
	t_img	image;

	image.img_ptr = mlx_new_image(engine->mlx, 2, lenght);
	image.addr = mlx_get_data_addr(image.img_ptr, &image.bpp, &image.line_len,
			&image.endian);
	image.h = 0;
	while (image.h < lenght)
	{
		image.w = 0;
		while (image.w < 2)
		{
			pixel = (image.h * image.line_len) + (image.w * 4);
			image.addr[pixel + 0] = (color) & 0xFF;
			image.addr[pixel + 1] = (color >> 8) & 0xFF;
			image.addr[pixel + 2] = (color >> 16) & 0xFF;
			image.addr[pixel + 3] = (color >> 24) & 0xFF;
			image.w++;
		}
		image.h++;
	}
	return (image);
}
