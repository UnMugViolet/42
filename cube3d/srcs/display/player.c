/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:17:48 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/11 12:30:07 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	set_player_position(t_player *player, char **map)
{
	size_t	i;
	size_t	j;

	i = -1;

	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_is_charset(map[i][j] , "NSEW"))
			{
				player->x = j + 0.5;
				player->y = i + 0.5;
				if (map[i][j] == 'N')
					player->angle = 0;
				else if (map[i][j] == 'S')
					player->angle = PI;
				else if (map[i][j] == 'W')
					player->angle = (3 * PI) / 2;
				else if (map[i][j] == 'E')
					player->angle = PI / 2;
			}
		}
	}
}
