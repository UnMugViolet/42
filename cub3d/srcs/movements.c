/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:11:03 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/06/26 10:22:20 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
* Changes the axis orientation of the player accordingly to the key pressed.
* @param t_engine*engine
* @param char_direction
* @return void
*/
void	ft_rotation(t_engine *engine, char direction)
{
	t_player	*player;

	player = &engine->data.player;
	if (direction == 'L')
	{
		player->angle += ROTATION;
		if (player->angle > 2 * PI)
			player->angle -= 2 * PI;
	}
	else if (direction == 'R')
	{
		player->angle -= ROTATION;
		if (player->angle < 0)
			player->angle += 2 * PI;
	}
	ft_angle_to_dir(player->angle, &player->dir);
}

/*
* Moves the player accordingly to its axis, checking 
* beforehand if he can move in the `x` axis or `y` axis.
* @param t_engine*engine
* @param doubledisplacement_x
* @param doubledisplacement_y
* @return void
*/
void	ft_move_player_axis(t_engine *engine,
		double displacement_x, double displacement_y)
{
	t_player	*player;
	t_pos		next;

	player = &engine->data.player;
	next.x = player->pos.x + displacement_x;
	next.y = player->pos.y;
	if (!is_wall(engine, next, engine->data.tile / 6))
		player->pos.x = next.x;
	next.x = player->pos.x;
	next.y = player->pos.y + displacement_y;
	if (!is_wall(engine, next, engine->data.tile / 6))
		player->pos.y = next.y;
}

/*
 *	Updates the player position using the `k_pressed` struct,
 *	it uses the `SPEED`
 *	and checks if there should be collision.
 *	@return(void)
 */
void	ft_handle_movement(t_engine *engine)
{
	t_player	*player;

	player = &engine->data.player;
	if (player->k_pressed[0])
		ft_move_player_axis(engine, cos(player->angle) * SPEED,
			-sin(player->angle) * SPEED);
	if (player->k_pressed[1])
		ft_move_player_axis(engine, -cos(player->angle) * SPEED,
			sin(player->angle) * SPEED);
	if (player->k_pressed[2])
		ft_move_player_axis(engine, -sin(player->angle) * SPEED,
			-cos(player->angle) * SPEED);
	if (player->k_pressed[3])
		ft_move_player_axis(engine, sin(player->angle) * SPEED,
			cos(player->angle) * SPEED);
	if (player->k_pressed[4])
		ft_rotation(engine, 'L');
	if (player->k_pressed[5])
		ft_rotation(engine, 'R');
}

int	ft_mouse_move(int x, int y, t_engine *engine)
{
	int const	center_x = engine->data.screen_size.x * 3 / 4;
	int const	delta_x = x - center_x;
	t_player	*player;

	player = &engine->data.player;
	(void)y;
	if (delta_x != 0)
	{
		engine->data.player.angle -= delta_x * SENSITIVITY;
		if (engine->data.player.angle > 2 * PI)
			engine->data.player.angle -= 2 * PI;
		if (engine->data.player.angle < 0)
			engine->data.player.angle += 2 * PI;
		ft_angle_to_dir(engine->data.player.angle, &engine->data.player.dir);
		mlx_mouse_move(engine->mlx, engine->win, center_x,
			engine->data.screen_size.y / 2);
		player->last_x_mouse = center_x;
	}
	return (0);
}
