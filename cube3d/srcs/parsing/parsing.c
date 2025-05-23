/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:57:20 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 18:24:34 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	is_valid_input(int ac, char **av, t_engine *engine)
{
	if (ac != 2)
		return (false);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
		return (false);
	engine->mlx = NULL;
	engine->win = NULL;
	engine->data.img = NULL;
	engine->data.addr = NULL;
	engine->data.bpp = 0;
	engine->data.line_len = 0;
	engine->data.endian = 0;
	return (true);
}
