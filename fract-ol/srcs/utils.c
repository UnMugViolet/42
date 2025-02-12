/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:14:02 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/11 12:17:09 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_display_usage(void)
{
	ft_putstr_fd("---------------------------------------------------\n", 2);
	ft_putstr_fd("                  FRACT-OL USAGE                   \n", 2);
	ft_putstr_fd("---------------------------------------------------\n\n", 2);
	ft_putstr_fd("             Usage: ./fractol [fractal]            \n", 2);
}
