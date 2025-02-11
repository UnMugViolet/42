/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:09:44 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/11 12:17:09 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_exit_free(t_engine *engine)
{
	if (engine->win)
		free(engine->win);
	if (engine->mlx)
		free(engine->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
