/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:21:15 by pjaguin           #+#    #+#             */
/*   Updated: 2025/03/06 16:38:59 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



/* Check the inputs from the user, exit if the value entered is incorrect
@param str
@return void */
void	ft_parse_prompt(char *prompt, char **env)
{
	if (!ft_strncmp(prompt, "exit", 5))
		ft_exit_clean(prompt);
	ft_init_struct_data(prompt, env);
}
