/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:38:07 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/24 14:31:26 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_start_minishell(void)
{
	int		run;
	char	*str;

	run = 1;
	while (run)
	{
		str = readline("$");
		if (str && *str == '\0')
			continue ;
		else if (str)
		{
			ft_printf("You entered: %s\n", str);
			add_history(str);
		}
		else
			run = 0;
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
