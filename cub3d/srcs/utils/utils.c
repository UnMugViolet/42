/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:57:30 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/30 14:32:33 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

size_t	ft_get_time_in_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_putstr_fd("Error: gettimeofday()\n", 2);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000));
}

void	clean_all(t_engine *engine)
{
	if (engine)
	{
		destroy_textures(engine);
		if (engine->data.map.array)
			ft_free_array_str(engine->data.map.array);
		if (engine->data.map.wall.img_ptr)
			mlx_destroy_image(engine->mlx, engine->data.map.wall.img_ptr);
		if (engine->data.img.img_ptr)
			mlx_destroy_image(engine->mlx, engine->data.img.img_ptr);
		if (engine->mlx && engine->win)
		{
			mlx_destroy_window(engine->mlx, engine->win);
			engine->win = NULL;
		}
		if (engine->mlx)
		{
			mlx_destroy_display(engine->mlx);
			free(engine->mlx);
			engine->mlx = NULL;
		}
	}
}

void	ft_display_usage(void)
{
	ft_printf("Usage: ./cub3D <map.cub>\n");
}

void	print_err_exit(char *err_msg, char *arg, t_engine *engine)
{
	if (err_msg)
		while (*err_msg)
			write(2, err_msg++, 1);
	if (err_msg && arg)
		write(2, " ", 1);
	if (arg)
		while (*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
	if (engine)
	{
		clean_all(engine);
		exit(1);
	}
}
