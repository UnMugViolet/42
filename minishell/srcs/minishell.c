/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:38:07 by pjaguin           #+#    #+#             */
/*   Updated: 2025/03/07 18:06:39 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Starts the engine, inifinte while loop to handle the input.
closes when encounter an unexpected input or exit case
@param env
@return void */
void	ft_start_minishell(t_data *data, char **env)
{
	char	*str;

	ft_init_data(data, NULL, env);
	while (true)
	{
		str = readline(CYN "minishell> "BLK);
		if (str && *str == '\0')
			continue ;
		else if (str)
		{
			ft_parse_prompt(str, data);
			ft_exec_prompt(str);
			add_history(str);
		}
		else if (EOF)
			break ;
		free(str);
	}
	ft_exit_clean(str, data);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	(void)ac;
	(void)av;
	ft_setup_signals();
	ft_start_minishell(&data, env);
	return (EXIT_SUCCESS);
}
