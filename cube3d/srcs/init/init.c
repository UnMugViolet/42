/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:57:13 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/11 16:13:32 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_init_player(t_engine *engine)
{
	t_player	*player;

	player = &engine->data.player;
	set_player_position(player, engine->data.map.array);
	player->pos.x = player->pos.x * engine->data.map.tile_size;
	player->pos.y = player->pos.y * engine->data.map.tile_size;
	player->image = ft_draw_square(engine, engine->data.map.tile_size / 3,
			YELLOW);
}

void	ft_init_map_2d(t_engine *engine, char *file)
{
	char	**map_file;

	map_file = get_map_file(file);
	engine->data.map.array = extract_map(map_file);
	ft_print_array_str_fd(engine->data.map.array, 1);
	ft_free_array_str(map_file);
	engine->data.map.size.y = map_rows(engine->data.map.array);
	engine->data.map.size.x = map_max_len(engine->data.map.array);
	engine->data.map.tile_size = engine->data.screen_size.y
		/ engine->data.map.size.y;
	if (engine->data.map.tile_size > engine->data.screen_size.x
		/ engine->data.map.size.x)
		engine->data.map.tile_size = engine->data.screen_size.x
			/ engine->data.map.size.x;
	engine->data.map.wall = ft_draw_square(engine,
			engine->data.map.tile_size, WHITE);
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
	mlx_get_screen_size(engine->mlx, &engine->data.screen_size.x,
		&engine->data.screen_size.y);
	engine->win = mlx_new_window(engine->mlx, engine->data.screen_size.x,
			engine->data.screen_size.y, file);
	if (!engine->win)
	{
		free(engine->mlx);
		exit(EXIT_FAILURE);
	}
	ft_init_map_2d(engine, file);
	get_textures(engine, file);
}
