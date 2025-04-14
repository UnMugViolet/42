/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:08:53 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/04/09 09:26:00 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Go through the prompt, get all the `pipes`, `heredocs`, `infiles`, 
	`outfiles` and `commands`. In case of error these subfunctions
	will print the specific syntax error.
	@param t_data*data
	@return void
*/
void	ft_parse_prompt(t_data *data)
{
	ft_get_pipes(data);
	ft_get_heredocs(data);
	ft_get_infiles(data);
	ft_get_outfiles(data);
	ft_get_commands(data);
	ft_replace_env_variable(data);
}
