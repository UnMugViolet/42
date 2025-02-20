/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:24:23 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/20 16:19:03 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_fractal(t_fractal *fractal, char *name)
{
	fractal->name = name;
	fractal->esc_value = 4;
	fractal->iter_nbr = 85;
	if (!ft_strncmp(name, "julia", 6))
		fractal->iter_nbr = 240;
	if (!ft_strncmp(name, "burningship", 12))
		fractal->iter_nbr = 51;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	ft_init_image(t_data *data, void *mlx)
{
	data->img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len,
			&data->endian);
}

void	ft_init_engine(t_engine *engine, char *fractal)
{
	ft_init_fractal(&engine->fractal, fractal);
	engine->mlx = mlx_init();
	if (!engine->mlx)
		exit(EXIT_FAILURE);
	engine->win = mlx_new_window(engine->mlx, WIN_WIDTH, WIN_HEIGHT,
			engine->fractal.name);
	if (!engine->win)
	{
		free(engine->mlx);
		exit(EXIT_FAILURE);
	}
	ft_init_image(&engine->data, engine->mlx);
}
