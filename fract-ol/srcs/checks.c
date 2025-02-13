/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:43:31 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/13 19:09:26 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdbool.h>

bool	is_valid_input(int ac, char **av, t_engine *engine)
{
	if (ac < 2 || ac > 4 || ac == 3)
		return (false);
	if (ac == 4)
	{
		if (ft_strncmp(av[1], "julia", 6))
			return (false);
		engine->fractal.julia_x = ft_atod(av[2]);
		engine->fractal.julia_y = ft_atod(av[3]);
	}
	if (ac == 2)
	{
		if (ft_strncmp(av[1], "mandelbrot", 11) && ft_strncmp(av[1], "burningship",
				12))
			return (false);
	}
	return (true);
}
