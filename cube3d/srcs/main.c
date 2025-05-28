/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:02:14 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/28 15:43:17 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int ac, char **av)
{
	t_engine	engine;

	ft_memset(&engine, 0, sizeof(t_engine));
	printf("MLX_PTR : %p, MLX_WIN : %p\n", engine.mlx, engine.win);
	if (!is_valid_input(ac, av, &engine))
		return (ft_display_usage(), EXIT_FAILURE);
	ft_init_window(&engine, av[1]);
	mlx_hook(engine.win, KeyPress, KeyPressMask, &ft_key_press, &engine);
	mlx_hook(engine.win, DestroyNotify, 0, &ft_destroy_event, &engine);
	mlx_loop(engine.mlx);
	return (EXIT_SUCCESS);
}
