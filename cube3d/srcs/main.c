/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:02:14 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/17 15:13:58 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int ac, char **av)
{
	t_engine	engine;

	ft_memset(&engine, 0, sizeof(t_engine));
	if (!is_valid_input(ac, av, &engine))
		return (ft_display_usage(), EXIT_FAILURE);
	ft_init_window(&engine, av[1]);
	ft_init_player(&engine);
	mlx_hook(engine.win, KeyPress, KeyPressMask, &ft_key_press, &engine);
	mlx_hook(engine.win, KeyRelease, KeyReleaseMask, &ft_key_release, &engine);
	mlx_hook(engine.win, MotionNotify, PointerMotionMask, &ft_mouse_move, &engine);
	mlx_loop_hook(engine.mlx, &game_loop, &engine);
	mlx_hook(engine.win, DestroyNotify, 0, &ft_destroy_event, &engine);
	mlx_loop(engine.mlx);
	return (EXIT_SUCCESS);
}
