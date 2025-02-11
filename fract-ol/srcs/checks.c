/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:43:31 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/11 12:17:09 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	ft_is_correct_input(int ac, char *str)
{
	if (ac != 2 && ac != 4)
		return (0);
	else if (ft_strncmp(str, "mandelbrot", 11) && ft_strncmp(str,
			"burning_ship", 13) && ft_strncmp(str, "julia", 6))
		return (0);
	else if (ac == 4 && ft_strncmp(str, "julia", 6))
		return (0);
	return (1);
}
