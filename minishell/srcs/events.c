/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:52:21 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/02/24 13:55:52 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void ft_handle_signal(int signal)
{
	if (signal == SIGINT || signal == SIGQUIT)
	{
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (signal == SIGTERM)
		ft_exit_clean(NULL);
}

int	ft_key_press(int keycode)
{
	(void)keycode;
	return (0);
}
