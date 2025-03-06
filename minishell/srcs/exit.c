/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:33:29 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/03/06 15:14:15 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit_clean(char *prompt)
{
	if (prompt)
		free(prompt);
	rl_clear_history();
	write(STDOUT_FILENO, "exit\n", 5);
	exit(EXIT_SUCCESS);
}
