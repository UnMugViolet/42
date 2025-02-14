/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:41:34 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/14 10:48:44 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_clean_displayed_string(char *iter_nbr, char *julia_x, char *julia_y)
{
	if (iter_nbr)
		free(iter_nbr);
	if (julia_x)
		free(julia_x);
	if (julia_y)
		free(julia_y);
}
