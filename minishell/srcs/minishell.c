/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:38:07 by pjaguin           #+#    #+#             */
/*   Updated: 2025/03/06 15:28:35 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_start_minishell(void)
{
	char	*str;

	while (true)
	{
		str = readline(CYN "minishell> "BLK);
		if (str && *str == '\0')
			continue ;
		else if (EOF)
			break ;
		else if (str)
		{
			ft_parse_prompt(str);
			ft_exec_prompt(str);
			add_history(str);
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
