/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:57:13 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/13 18:27:06 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_init_player(t_engine *engine)
{
	t_player	*player;

	player = &engine->data.player;
	player->size = engine->data.map.tile_size / 3;
	set_player_position(player, engine->data.map.array);
	ft_draw_player(engine);
}

void	ft_init_map_2d(t_engine *engine, char *file)
{
	char	**map_file;
	t_point	map_size;

	map_file = get_map_file(file);
	map_size.x = engine->data.map.size.x;
	engine->data.map.array = extract_map(map_file);
	engine->data.map.size.y = map_rows(engine->data.map.array) / 2;
	map_size.x = map_max_len(engine->data.map.array);
	engine->data.map.tile_size = engine->data.screen_size.y
		/ engine->data.map.size.y;
	if (engine->data.map.tile_size > engine->data.screen_size.x / map_size.x)
		engine->data.map.tile_size = engine->data.screen_size.x / map_size.x;
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
	mlx_get_screen_size(engine->mlx, &engine->data.screen_size.x,
		&engine->data.screen_size.y);
	engine->win = mlx_new_window(engine->mlx, engine->data.screen_size.x,
			engine->data.screen_size.y, file);
	if (!engine->win)
	{
		free(engine->mlx);
		exit(EXIT_FAILURE);
	}
	engine->data.img.img_ptr = mlx_new_image(engine->mlx, engine->data.screen_size.x,
			engine->data.screen_size.y);
	engine->data.img.addr = mlx_get_data_addr(engine->data.img.img_ptr,
		&engine->data.img.bpp, &engine->data.img.line_len,
		&engine->data.img.endian);
	ft_init_map_2d(engine, file);
	get_textures(engine, file);
}
