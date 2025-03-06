/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:38:07 by pjaguin           #+#    #+#             */
/*   Updated: 2025/03/06 14:21:05 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_start_minishell(void)
{
	char	*str;

	while (true)
	{
		str = readline("$");
		if (str && *str == '\0')
			continue ;
		else if (str)
		{
			ft_parse_prompt(str);
			ft_exec_prompt(str);
			add_history(str);
		}
		else if (EOF)
		{
			write(STDOUT_FILENO, "exit\n", 5);
			break ;
		}
		else if (!ft_strncmp(str, "history", 7))
		{
			ft_printf("History handle later\n");
		}
		free(str);
	}
	ft_exit_clean(str);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
	ft_setup_signals();
	ft_start_minishell();
	return (EXIT_SUCCESS);
}
