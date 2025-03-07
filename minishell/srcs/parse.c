/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:21:15 by pjaguin           #+#    #+#             */
/*   Updated: 2025/03/07 17:47:58 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Check the inputs from the user, exit if the value entered is incorrect
@param str
@return void */
void	ft_parse_prompt(char *prompt, t_data *data)
{
	if (!ft_strncmp(prompt, "exit", 5))
		ft_exit_clean(prompt);
	data->prompt = prompt;
}
