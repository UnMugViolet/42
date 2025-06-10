/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:57:13 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/10 10:34:50 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*
* Initiate the MLX `engine` using the data in the `file`
* @param t_engine*engine
* @param char*file
* @return (void)
*/
void	ft_init_window(t_engine *engine, char *file)
{
	t_point screen_size;

	engine->mlx = mlx_init();
	if (!engine->mlx)
		exit(EXIT_FAILURE);
	ft_memset(&screen_size, 0, sizeof(t_point));
	mlx_get_screen_size(engine->mlx, &screen_size.x,  &screen_size.y);
	engine->win = mlx_new_window(engine->mlx, screen_size.x, screen_size.y,
			file);
	if (!engine->win)
	{
		free(engine->mlx);
		exit(EXIT_FAILURE);
	}
	get_textures(engine, file);
}
