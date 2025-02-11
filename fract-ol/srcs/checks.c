/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:43:31 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/11 12:35:47 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdbool.h>

bool	is_valid_input(int ac, char *str)
{
	if (ac < 2 || ac > 4 || ac == 3)
		return (false);
	if (ac == 4)
	{
		if (ft_strncmp(str, "julia", 6))
			return (false);
	}
	if (ac == 2)
	{
		if (ft_strncmp(str, "mandelbrot", 11) && ft_strncmp(str, "burningship", 12))
			return (false);
	}
	return (true);
}
