/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boolean_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:39:26 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/09 13:02:47 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_is_correct_input(char *prompt)
{
	while (ft_is_whitespace(*prompt))
		prompt++;
	if (!*prompt)
		return (false);
	return (true);
}

/*
	Check if the `str` given as parameter is an environment variable
	A string is considered an environment variable if it starts with a '$'
	followed by an alphanumeric character. It can also be "$?" or "$_"
	@param char*str
	@return bool
*/
bool	ft_is_env_var(char *str)
{
	if (!str)
		return (false);
	if ((!ft_strncmp(str, "$", 1) && ft_isalnum(str[1])) || !ft_strncmp(str,
			"$?", 2) || !ft_strncmp(str, "$_", 2))
		return (true);
	return (false);
}

/*
	Checks if the `prompt` is left with open quotes
	@param char*prompt
	@return bool
*/
bool	ft_is_closed_quotes(char *prompt)
{
	bool	in_single_quote;
	bool	in_double_quote;
	int		i;

	i = -1;
	in_single_quote = false;
	in_double_quote = false;
	while (prompt[++i])
	{
		if (prompt[i] == '\'' && !in_double_quote)
			in_single_quote = !in_single_quote;
		if (prompt[i] == '\"' && !in_single_quote)
			in_double_quote = !in_double_quote;
	}
	return (!(in_single_quote || in_double_quote));
}

/*
	Checks if the beginning of the string `str` is part of
	the `metachar` array.
	@param char*str
	@param t_data*data
	@return bool
*/
bool	ft_is_token(char *str, t_data *data)
{
	int	i;

	i = -1;
	while (data->metachar[++i])
		if (ft_strncmp(str, data->metachar[i], ft_strlen(data->metachar[i])))
			return (true);
	return (false);
}

/*
	Checks if `cmd` is a builtin function.
	@param char*cmd
	@return bool	
*/
bool	ft_is_builtin(char *cmd)
{
	char	**tmp;
	int		i;

	tmp = ft_split(BUILTINS, ' ');
	i = 0;
	while (tmp[i])
	{
		if (!ft_strncmp(cmd, tmp[i], ft_strlen(tmp[i])))
			return (ft_free_array_str(tmp), true);
		i++;
	}
	return (ft_free_array_str(tmp), false);
}
