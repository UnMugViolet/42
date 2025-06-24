/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:45:52 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/23 10:26:41 by unmugviolet      ###   ########.fr       */
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
