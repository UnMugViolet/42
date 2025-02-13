/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:50:04 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/13 19:00:25 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_engine	engine;

	(void)av;
	if (!is_valid_input(ac, av, &engine))
		return (ft_display_usage(), EXIT_FAILURE);
	ft_init_engine(&engine, av[1]);
	fractal_render(&engine);
	mlx_hook(engine.win, KeyPress, KeyPressMask, &ft_key_press, &engine);
	mlx_hook(engine.win, ButtonPress, ButtonPressMask, &ft_mouse_handle,
		&engine);
	mlx_hook(engine.win, DestroyNotify, 0, &ft_destroy_event, &engine);
	mlx_loop(engine.mlx);
	return (EXIT_SUCCESS);
}
