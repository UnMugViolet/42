/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:17:48 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/16 17:46:47 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_clear_player(t_engine *engine)
{
    int		tile;
    t_point	center;

    tile = engine->data.map.tile_size;
    center.x = (int)(engine->data.player.pos.x * tile);
    center.y = (int)(engine->data.player.pos.y * tile);
    ft_draw_square(engine, (t_point){center.x, center.y}, engine->data.player.size, BLACK);
}

void	ft_draw_player(t_engine *engine)
{
	int		tile;
	t_point	center;
	t_point	end;

	(void)end;
	tile = engine->data.map.tile_size;
    center.x = (int)(engine->data.player.pos.x * tile);
    center.y = (int)(engine->data.player.pos.y * tile);
	ft_draw_square(engine, (t_point){center.x, center.y}, engine->data.player.size, YELLOW);
	end.x = center.x + cos(engine->data.player.angle) * (tile / 2);
	end.y = center.y + sin(engine->data.player.angle) * (tile / 2);
	ft_draw_line(engine, center, end, BLACK);
}

/*
 *	Set the player on the map according to the spawn point.
 *	The direction is taken into account and the player `struct` stores the data
 *	@return(void)
 */
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
			if (ft_is_charset(map[i][j], "NSEW"))
			{
				player->pos.x = j + 0.5;
				player->pos.y = i + 0.5;
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

/*
 *	Updates the player position using the `wsad` struct, it uses the `SPEED`
 *	and checks if there should be collision.
 *	@return(void)
 */
int	update_player_position(t_engine *engine)
{
	t_player	*player;
	char const	**map = (const char **)engine->data.map.array;
	int const	size = engine->data.map.tile_size;

	player = &engine->data.player;
	if (player->wsad[0] && !is_wall(map, (t_pos){player->pos.x, player->pos.y
			- (1 * SPEED)}, size))
		return (ft_clear_player(engine), player->pos.y -= 1 * SPEED, 1);
	if (player->wsad[1] && !is_wall(map, (t_pos){player->pos.x, player->pos.y
			+ (1 * SPEED)}, size))
		return (ft_clear_player(engine), player->pos.y += 1 * SPEED, 1);
	if (player->wsad[2] && !is_wall(map, (t_pos){player->pos.x - (1 * SPEED),
			player->pos.y}, size))
		return (ft_clear_player(engine), player->pos.x -= 1 * SPEED, 1);
	if (player->wsad[3] && !is_wall(map, (t_pos){player->pos.x + (1 * SPEED),
			player->pos.y}, size))
		return (ft_clear_player(engine), player->pos.x += 1 * SPEED, 1);
	return (0);
}
