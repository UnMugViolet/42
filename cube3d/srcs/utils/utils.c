/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:57:30 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/28 14:53:29 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	clean_all(t_engine *cube)
{
	if (cube)
	{
		destroy_textures(cube);
		if (cube->mlx && cube->win)
			mlx_destroy_window(cube->mlx, cube->win);
		if (cube->mlx)
			mlx_destroy_display(cube->mlx);
	}
}

void	ft_display_usage(void)
{
	ft_printf("Usage: ./cube3d <map.cub>\n");
}

void	print_err_exit(char *err_msg, char *arg, t_engine *cube)
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
	if (cube)
	{
		clean_all(cube);
		exit(1);
	}
}
