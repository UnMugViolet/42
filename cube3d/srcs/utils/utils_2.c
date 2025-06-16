/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:45:52 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/16 15:13:16 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_put_pixel(t_engine *engine, t_point init_point, int color)
{
	int			pixel;
	t_img const	img = engine->data.img;

	pixel = (init_point.y * img.line_len) + (init_point.x * 4);
	img.addr[pixel + 0] = (color) & 0xFF;
	img.addr[pixel + 1] = (color >> 8) & 0xFF;
	img.addr[pixel + 2] = (color >> 16) & 0xFF;
	img.addr[pixel + 3] = (color >> 24) & 0xFF;
}

size_t	ft_get_time_in_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_putstr_fd("Error: gettimeofday()\n", 2);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000));
}

void	ft_draw_square(t_engine *engine, t_point pos, int width, int color)
{
	t_point	pixel;

	pixel.y = 0;
	while (pixel.y < width)
	{
		pixel.x = 0;
		while (pixel.x < width)
		{
			ft_put_pixel(engine,
				(t_point){pos.x + pixel.x, pos.y + pixel.y}, color);
			pixel.x++;
		}
		pixel.y++;
	}
}

void	ft_display_map_2d(t_engine *engine)
{
	int		tile_size;
	t_point	p;
	t_point	p_tile;

	engine->data.map.size.y = map_rows(engine->data.map.array);
	engine->data.map.size.x = map_max_len(engine->data.map.array);
	tile_size = engine->data.screen_size.y / engine->data.map.size.y;
	if (tile_size > engine->data.screen_size.x / engine->data.map.size.x)
		tile_size = engine->data.screen_size.x / engine->data.map.size.x;
	p.y = 0;
	while (p.y < engine->data.map.size.y)
	{
		p.x = 0;
		while (p.x < engine->data.map.size.x)
		{
			p_tile.x = p.x * tile_size;
			p_tile.y = p.y * tile_size;
			if (engine->data.map.array[p.y][p.x] == '1')
				ft_draw_square(engine, p_tile, tile_size - 2 , WHITE);
			else if (engine->data.map.array[p.y][p.x] == '0' || ft_is_charset(engine->data.map.array[p.y][p.x], "SNWE"))
				ft_draw_square(engine, p_tile, tile_size - 2 , RED);
			p.x++;
		}
		p.y++;
	}
}

void	ft_draw_line(t_engine *engine, int lenght, int color)
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
}
