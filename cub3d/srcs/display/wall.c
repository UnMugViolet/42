/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:18:09 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/30 18:48:03 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Get the pixel color from the texture image at the specified coordinates.
 * The texture is assumed to be a valid image with width and height.
 * Returns 0 if the coordinates are out of bounds.
 */
int	get_texture_pixel(t_img *texture, int x, int y, double ray_len)
{
	int		color;
	double	shadow;
	int		rgb[3];

	if (x < 0 || x >= texture->w || y < 0 || y >= texture->h)
		return (0);
	color = *(int *)(texture->addr + y * texture->line_len + x * (texture->bpp
				/ 8));
	shadow = fmax(0.3, fmin(1.0, 1.0 - ray_len / 20.0));
	rgb[0] = ((color >> 16) & 0xFF) * shadow;
	rgb[1] = ((color >> 8) & 0xFF) * shadow;
	rgb[2] = (color & 0xFF) * shadow;
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

/*
 * Determine the texture index based on the angle and whether
 * the wall is vertical.
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

void	ft_add_texture(t_engine *engine, double angle, int height, t_ray ray)
{
	int		texture_index;
	t_img	*texture;
	t_point	tex;
	double	tex_pos;
	double	step;

	texture_index = get_wall_texture_index(angle, ray.is_vertical);
	texture = &engine->data.map.textures[texture_index];
	step = (double)texture->h / height;
	tex_pos = (ray.start.y - WIN_H / 2 + height / 2) * step;
	if (ray.is_vertical)
		tex.x = (int)(ray.hit.y * texture->w) % texture->w;
	else
		tex.x = (int)(ray.hit.x * texture->w) % texture->w;
	if (texture_index == 1 || texture_index == 3)
		tex.x = texture->w - 1 - tex.x;
	while (ray.start.y < ray.end.y)
	{
		tex.y = (int)tex_pos % texture->h;
		tex_pos += step;
		ft_put_pixel(engine, (t_point){ray.start.x, ray.start.y},
			get_texture_pixel(texture, tex.x, tex.y, ray.len));
		ray.start.y++;
	}
}

void	ft_display_wall(t_engine *engine, int v_pxl, double angle, t_ray ray)
{
	int				height;
	double const	correction_factor = cos(angle - engine->data.player.angle);

	height = WIN_H / ((ray.len * correction_factor) * 0.5);
	ray.start.x = WIN_W - v_pxl;
	ray.start.y = WIN_H / 2 - height / 2;
	if (ray.start.y < 0)
		ray.start.y = 0;
	ray.end.y = WIN_H / 2 + height / 2;
	if (ray.end.y > WIN_H)
		ray.end.y = WIN_H;
	ft_add_texture(engine, angle, height, ray);
}
