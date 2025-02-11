/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:52:54 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/11 14:17:27 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_square(t_complex z)
{
	t_complex	res;

	res.x = z.x * z.x - z.y * z.y;
	res.y = 2 * z.x * z.y;
	return (res);
}

t_complex	complex_sum(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

double	map(double unsc_nb, double n_min, double n_max, double o_max)
{
	double	o_min;

	o_min = 0;
	return ((unsc_nb - o_min) * (n_max - n_min) / (o_max - o_min) + n_min);
}
