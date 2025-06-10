/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:45:52 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/10 14:08:59 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_put_square(t_engine *engine, t_point point, t_img image)
{
	mlx_put_image_to_window(engine->mlx, engine->win, image.img_ptr, point.x,
		point.y);
}

t_img	ft_draw_square(t_engine *engine, int wideness, int color)
{
	int		pixel;
	t_img	image;

	image.img_ptr = mlx_new_image(engine->mlx, wideness, wideness);
	image.addr = mlx_get_data_addr(image.img_ptr, &image.bpp, &image.line_len,
			&image.endian);
	image.h = 0;
	while (image.h < wideness)
	{
		image.w = 0;
		while (image.w < wideness)
		{
			pixel = (image.h * image.line_len) + (image.w * 4);
			if (image.endian == 0)
			{
				image.addr[pixel + 0] = (color) &0xFF;
				image.addr[pixel + 1] = (color >> 8) & 0xFF;
				image.addr[pixel + 2] = (color >> 16) & 0xFF;
				image.addr[pixel + 3] = (color >> 24) & 0xFF;
			}
			else if (image.endian == 1)
			{
				image.addr[pixel + 0] = (color >> 24) & 0xFF;
				image.addr[pixel + 1] = (color >> 16) & 0xFF;
				image.addr[pixel + 2] = (color >> 8) & 0xFF;
				image.addr[pixel + 3] = (color) &0xFF;
			}
			image.w++;
		}
		image.h++;
	}
	return (image);
}
