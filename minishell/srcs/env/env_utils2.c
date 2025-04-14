/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:33:42 by yguinio           #+#    #+#             */
/*   Updated: 2025/04/07 11:43:47 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Returns the adress of the `variable` string inside the `env` array.
	Returns `NULL` if not found.
	@param t_data*data
	@param char*variable
	@return char *
*/
char	*ft_get_env_var_adress(t_data *data, char *variable)
{
	int		i;
	size_t	size;

	i = -1;
	size = ft_strlen(variable);
	while (data->env[++i])
		if (ft_strncmp(data->env[i], variable, size) == 0
			&& data->env[i][size] == '=')
			return (data->env[i]);
	return (NULL);
}

/*
	Update the `last_exit_value` in the `data` struct to the `value`
	@param t_data*data
	@param int value
*/
void	ft_update_last_exit_value(t_data *data, int value)
{
	free(data->last_exit_value);
	data->last_exit_value = ft_itoa(value);
}

/*
	Returns the name of the first `$variable` in the string `str`
	`NULL` if no `$variable` is found
	@param char*str
	@return char *
*/
char	*ft_get_env_var_name(char *str)
{
	char	*res;
	int		size;

	size = 0;
	str = ft_strchr(str, '$');
	if (!str)
		return (NULL);
	str++;
	if (*str == '?')
		return (ft_strdup("?"));
	while (*str && (ft_isalnum(*str) || *str == '_'))
	{
		size++;
		str++;
	}
	res = (char *)ft_calloc(sizeof(char), size + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, str - size, size + 1);
	return (res);
}

/*
	Returns the value of the `variable` if found in the `env` array.
	@param char** env
	@param char* variable
	@return char *
*/
char	*ft_get_associated_env_value(t_data *data, char *variable)
{
	int		i;
	size_t	size;

	i = 0;
	if (!data->env || !variable)
		return (ft_strdup(""));
	if (!(*variable))
		return (ft_strdup("$"));
	size = ft_strlen(variable);
	if (!ft_strncmp(variable, "?", 2))
		return (ft_strdup(data->last_exit_value));
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], variable, size) == 0
			&& data->env[i][size] == '=')
			return (ft_strdup(data->env[i] + size + 1));
		i++;
	}
	return (ft_strdup(""));
}
