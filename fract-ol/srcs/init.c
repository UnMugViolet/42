/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:24:23 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/11 12:25:15 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	 ft_init_fractal(t_fractal *fractal, char *name)
{
	fractal->name = name;
}

static void	 ft_init_image(t_data *data, void *mlx)
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
	ft_init_image(&engine->data, engine->mlx);
	ft_init_fractal(&engine->fractal, fractal);
}
