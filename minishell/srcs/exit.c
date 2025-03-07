/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:33:29 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/03/07 18:05:41 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void ft_clean_structs(t_data *data)
{
	ft_free_array_str(data->paths);
} 

void	ft_exit_clean(char *prompt, t_data *data)
{
	if (prompt)
		free(prompt);
	ft_clean_structs(data);
	rl_clear_history();
	write(STDOUT_FILENO, "exit\n", 5);
	exit(EXIT_SUCCESS);
}
