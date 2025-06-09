/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:57:13 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/09 12:41:37 by yguinio          ###   ########.fr       */
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
	engine->mlx = mlx_init();
	if (!engine->mlx)
		exit(EXIT_FAILURE);
	engine->win = mlx_new_window(engine->mlx, WIN_WIDTH, WIN_HEIGHT,
			file);
	if (!engine->win)
	{
		free(engine->mlx);
		exit(EXIT_FAILURE);
	}
	get_textures(engine, file);
}
