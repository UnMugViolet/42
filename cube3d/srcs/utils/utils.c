/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:57:30 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/29 14:50:06 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	clean_all(t_engine *engine)
{
	if (engine)
	{
		destroy_textures(engine);
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
	ft_printf("Usage: ./cube3d <map.cub>\n");
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
