/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:09:44 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/07 15:11:16 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_exit_free(t_engine *engine)
{
	if (engine->win)
		free(engine->win);
	exit(EXIT_FAILURE);
}
