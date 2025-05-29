/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:20:00 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/29 16:13:32 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_key_press(int keycode, t_engine *engine)
{
	if (keycode == XK_Escape)
		ft_destroy_event(engine);
	return (EXIT_SUCCESS);
}

int	ft_destroy_event(t_engine *engine)
{
	clean_all(engine);
	exit(EXIT_SUCCESS);
}
