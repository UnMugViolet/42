/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:14:02 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/14 15:43:02 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_display_usage(void)
{
	ft_putstr_fd("---------------------------------------------------\n", 2);
	ft_putstr_fd("                  FRACT-OL USAGE                   \n", 2);
	ft_putstr_fd("---------------------------------------------------\n\n", 2);
	ft_putstr_fd("          Usage: ./fractol [fractal_name]          \n", 2);
	ft_putstr_fd("       Available: [mandelbrot] [burningship] [julia]\n", 2);
	ft_putstr_fd("       Specific case: ./fractol julia [x][y]       \n\n", 2);
	ft_putstr_fd("       Reset: [r]                                  \n", 2);
	ft_putstr_fd("       Iterations: [q] [w]                        \n", 2);
	ft_putstr_fd("       Zoom: [scroll] [up] [down]                  \n", 2);
	ft_putstr_fd("       Move : arrow [up] [down] [left] [right]     \n", 2);
	ft_putstr_fd("---------------------------------------------------\n", 2);
}
