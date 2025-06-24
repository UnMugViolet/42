/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:57:13 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/24 16:57:40 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_center_mouse(t_engine *engine)
{
	int const	center_x = engine->data.screen_size.x / 2;
	int const	center_y = engine->data.screen_size.y / 2;

	mlx_mouse_move(engine->mlx, engine->win, center_x, center_y);
}

/*
 *	Set the player on the map according to the spawn point.
 *	The direction is taken into account and the player `struct` stores the data
 *	@return(void)
 */
static void	set_player_position(t_player *player, char **map)
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
					player->angle = PI / 2;
				else if (map[i][j] == 'S')
					player->angle = 3 * PI / 2;
				else if (map[i][j] == 'E')
					player->angle = 0;
				else if (map[i][j] == 'W')
					player->angle = PI;
			}
		}
	}
	player->angle = 1.58;
}

void	ft_init_player(t_engine *engine)
{
	t_player	*player;

	player = &engine->data.player;
	player->size = engine->data.tile / 3;
	set_player_position(player, engine->data.map.array);
	player->dir.x = cos(player->angle);
	player->dir.y = sin(player->angle);
	player->plan.x = -player->dir.y * 0.66f;
	player->plan.y = player->dir.x * 0.66f;
}

void	ft_init_map_2d(t_engine *engine, char *file)
{
	char	**map_file;
	t_point	map_size;

	map_file = get_map_file(file);
	map_size.x = engine->data.map.size.x;
	engine->data.map.array = extract_map(map_file);
	engine->data.map.size.y = map_rows(engine->data.map.array);
	map_size.x = map_max_len(engine->data.map.array);
	engine->data.tile = (engine->data.screen_size.y
			/ engine->data.map.size.y) / 2;
	if (engine->data.tile > (engine->data.screen_size.x / map_size.x)
		/ 2)
		engine->data.tile = (engine->data.screen_size.x / map_size.x)
			/ 2;
	ft_free_array_str(map_file);
}

/*
 * Initiate the MLX `engine` using the data in the `file`
 * @param t_engine*engine
 * @param char*file
 * @return (void)
 */
void	ft_init_window(t_engine *engine, char *file)
{
	engine->mlx = mlx_init();
	if (!engine->mlx)
		exit(EXIT_FAILURE);
	ft_memset(&engine->data.screen_size, 0, sizeof(t_point));
	engine->data.screen_size.x = WIN_W;
	engine->data.screen_size.y = WIN_H;
	engine->win = mlx_new_window(engine->mlx, engine->data.screen_size.x,
			engine->data.screen_size.y, file);
	if (!engine->win)
	{
		free(engine->mlx);
		exit(EXIT_FAILURE);
	}
	engine->data.img.img_ptr = mlx_new_image(engine->mlx,
			engine->data.screen_size.x, engine->data.screen_size.y);
	engine->data.img.addr = mlx_get_data_addr(engine->data.img.img_ptr,
			&engine->data.img.bpp, &engine->data.img.line_len,
			&engine->data.img.endian);
	engine->data.img.h = engine->data.screen_size.y;
	engine->data.img.w = engine->data.screen_size.x;
	ft_init_map_2d(engine, file);
	get_textures(engine, file);
	get_colors(engine, file);
}
