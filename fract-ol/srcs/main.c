/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:50:04 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/10 11:28:25 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int ac, char **av)
{
	t_engine	engine;

	(void)av;
	if (ac != 2)
		return (ft_display_usage(), EXIT_FAILURE);
	ft_init_engine(&engine, av[1]);
	mlx_hook(engine.win, KeyPress, KeyPressMask, &ft_key_press, &engine);
	mlx_hook(engine.win, DestroyNotify, 0, &ft_destroy_event, &engine);
	mlx_loop(engine.mlx);
	return (EXIT_SUCCESS);
}
