/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:43:43 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/30 11:48:57 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	tile(int *tile_set)
{
	static int	tile;

	if (!tile && tile_set)
	{
		tile = *tile_set;
		return (tile);
	}
	else
		return (tile);
}
