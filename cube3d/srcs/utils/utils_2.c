/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:45:52 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/18 14:32:39 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_put_pixel(t_engine *engine, t_point init_point, int color)
{
	int			pixel;
	t_img const	img = engine->data.img;

 	if (init_point.x < 0 || init_point.x >= img.w
		|| init_point.y < 0 || init_point.y >= img.h)
		return ;
	pixel = (init_point.y * img.line_len) + (init_point.x * 4);
	img.addr[pixel + 0] = (color) & 0xFF;
	img.addr[pixel + 1] = (color >> 8) & 0xFF;
	img.addr[pixel + 2] = (color >> 16) & 0xFF;
	img.addr[pixel + 3] = (color >> 24) & 0xFF;
}

void	ft_draw_square(t_engine *engine, t_point pos, int width, int color)
{
	int	x;
	int	y;
	int	half;

	half = width / 2;
	y = -half;
	while (y < width - half)
	{
		x = -half;
		while (x < width - half)
		{
			ft_put_pixel(engine, (t_point){pos.x + x, pos.y + y}, color);
			x++;
		}
		y++;
	}
}

void	ft_draw_map_2d(t_engine *engine)
{
	int		tile_size;
	t_point	p;
	t_point	p_tile;
	double	angle = engine->data.player.angle;
	double	player_x = engine->data.player.pos.x;
	double	player_y = engine->data.player.pos.y;
	int		center_x = engine->data.screen_size.x / 4;
	int		center_y = engine->data.screen_size.y / 2;

	engine->data.map.size.y = map_rows(engine->data.map.array);
	engine->data.map.size.x = map_max_len(engine->data.map.array);
	tile_size = (engine->data.screen_size.y / engine->data.map.size.y) / 2;
	if (tile_size > (engine->data.screen_size.x / engine->data.map.size.x / 4))
		tile_size = (engine->data.screen_size.x / engine->data.map.size.x) / 4;
	p.y = 0;
	while (p.y < engine->data.map.size.y)
	{
		p.x = 0;
		while (p.x < engine->data.map.size.x)
		{
			double cx = p.x + 0.5;
			double cy = p.y + 0.5;

			double rel_x = (cx - player_x) * tile_size;
			double rel_y = (cy - player_y) * tile_size;

			double rot_x = rel_x * cos(angle - PI / 2) - rel_y * sin(angle - PI / 2);
			double rot_y = rel_x * sin(angle - PI / 2) + rel_y * cos(angle - PI / 2);

			p_tile.x = center_x + (int)rot_x;
			p_tile.y = center_y + (int)rot_y;

			if (engine->data.map.array[p.y][p.x] == '1')
				ft_draw_square(engine, p_tile, tile_size - 2, WHITE);
			else if (engine->data.map.array[p.y][p.x] == '0' ||
					ft_is_charset(engine->data.map.array[p.y][p.x], "SNWE"))
				ft_draw_square(engine, p_tile, tile_size - 2, RED);
			p.x++;
		}
		p.y++;
	}
	draw_centered_triangle(engine, (t_pos){center_x, center_y}, (t_point){10, 10}, YELLOW);
}

static int	ft_get_err(int dx, int dy)
{
	int	err;

	if (abs(dx) < abs(dy))
		err = -abs(dy) / 2;
	else
		err = abs(dx) / 2;
	return (err);
}

void	ft_draw_line(t_engine *engine, t_point start, t_point end, int color)
{
	const int		dx = end.x - start.x;
	const int		dy = end.y - start.y;
	int				err;
	int				e2;

	err = ft_get_err(dx, dy);
	while (true)
	{
		ft_put_pixel(engine, start, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		e2 = err;
		if (e2 > -abs(dx))
		{
			err -= abs(dy);
			start.x += dx / abs(dx);
		}
		if (e2 < abs(dy))
		{
			err += abs(dx);
			start.y += dy / abs(dy);
		}
	}
}
