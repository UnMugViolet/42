/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:24:23 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/10 12:28:30 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	ft_init_image(t_data *data, void *mlx)
{
	data->img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len,
			&data->endian);
	data->bpp = 0;
	data->line_len = 0;
	data->endian = 0;
}

void	ft_init_engine(t_engine *engine, char *fractal)
{
	engine->mlx = mlx_init();
	if (!engine->mlx)
		exit(EXIT_FAILURE);
	engine->win = mlx_new_window(engine->mlx, WIN_WIDTH, WIN_HEIGHT,
			"fract_ol");
	if (!engine->win)
		free(engine->mlx);
	engine->fractal.name = fractal;
	ft_init_image(&engine->data, engine->mlx);
}
