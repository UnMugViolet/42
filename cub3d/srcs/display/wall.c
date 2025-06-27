/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:18:09 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/27 15:57:58 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Get the pixel color from the texture image at the specified coordinates.
 * The texture is assumed to be a valid image with width and height.
 * Returns 0 if the coordinates are out of bounds.
*/
int	get_texture_pixel(t_img *texture, int x, int y)
{
	char	*pixel;
	int		offset;

	if (x < 0 || x >= texture->w || y < 0 || y >= texture->h)
		return (0);
	offset = y * texture->line_len + x * (texture->bpp / 8);
	pixel = texture->addr + offset;
	return (*(int *)pixel);
}

/*
 * Determine the texture index based on the angle and whether the wall is vertical.
 * Vertical walls (East/West) are determined by the cos of the angle,
 * while horizontal walls (North/South) are determined by the sine of the angle.
*/
int	get_wall_texture_index(double angle, bool is_vertical)
{
	if (is_vertical)
	{
		if (cos(angle) > 0)
			return (2);
		else
			return (3);
	}
	else
	{
		if (sin(angle) > 0)
			return (0);
		else
			return (1);
	}
}

void	ft_add_texture(t_engine *engine, double angle, bool is_vertical, t_pos wall_hit, int height, t_point start, t_point end)
{
	int				texture_index;
	t_img			*texture;
	t_point			tex;
	double			tex_pos;
	double			step;
	int				color;

	texture_index = get_wall_texture_index(angle, is_vertical);
	texture = &engine->data.map.textures[texture_index];
	step = (double)texture->h / height;
	tex_pos = (start.y - WIN_H / 2 + height / 2) * step;
	if (is_vertical)
		tex.x = (int)(wall_hit.y * texture->w) % texture->w;
	else
		tex.x = (int)(wall_hit.x * texture->w) % texture->w;
	while (start.y < end.y)
	{
		tex.y = (int)tex_pos % texture->h;
		tex_pos += step;
		color = get_texture_pixel(texture, tex.x, tex.y);
		ft_put_pixel(engine, (t_point){start.x, start.y}, color);
		start.y++;
	}
}

void	ft_display_wall(t_engine *engine, int v_pxl, double ray_len, double angle, t_pos wall_hit, bool is_vertical)
{
	int				height;
	double const	correction_factor = cos(angle - engine->data.player.angle);
	t_point			start;
	t_point			end;

	height = WIN_H / ((ray_len * correction_factor) * 0.5);
	start.x = WIN_W - v_pxl;
	start.y = WIN_H / 2 - height / 2;
	if (start.y < 0)
		start.y = 0;
	end.y = WIN_H / 2 + height / 2;
	if (end.y > WIN_H)
		end.y = WIN_H;
	ft_add_texture(engine, angle, is_vertical, wall_hit, height, start, end);
}
