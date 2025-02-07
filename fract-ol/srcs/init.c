/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:24:23 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/07 15:36:36 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_init_image(t_data *data, char *fractal, void *mlx)
{
	(void)fractal;
	data->img = mlx_new_image(mlx, 750, 500);
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
	engine->win = mlx_new_window(engine->mlx, 750, 500, "fract_ol");
	if (!engine->win)
		ft_exit_free(engine);
	ft_init_image(&engine->data, fractal, engine->mlx);
	mlx_hook(engine->win, DestroyNotify, StructureNotifyMask, &ft_exit_free, engine);
	mlx_loop(engine->mlx);
}
