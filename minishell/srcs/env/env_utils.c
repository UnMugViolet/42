/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:33:42 by yguinio           #+#    #+#             */
/*   Updated: 2025/04/05 17:33:22 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Checks if the `str` string is rightfully formated for an `env` variable
	(only alphanumeric characters and `_` are allowed, and it must not start
	with a digit).
	@param char*str
	@return bool
*/
static bool	ft_check_env_var_format(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (ft_fprintf(ERR_OUT, ERR_EXPORT_SYNTAX, str), false);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (ft_fprintf(ERR_OUT, ERR_EXPORT_SYNTAX, str), false);
		i++;
	}
	if (str[i] == '=')
		return (true);
	return (ft_fprintf(ERR_OUT, ERR_EXPORT_SYNTAX, str), false);
}

static void	ft_free_all(char **new_env, char *var_check)
{
	ft_free_array_str(new_env);
	free(var_check);
}

/*
	Add the new variable and its value contained in `str` to the `env` array
	in the `t_data` struct.
	@param t_data*data
	@param char*str
	@return void
*/
int	ft_create_env_var(t_data *data, char *str)
{
	int		i;
	char	**new_env;
	char	*var_check;

	i = 0;
	if (!ft_check_env_var_format(str))
		return (1);
	var_check = ft_substr(str, 0, ft_strchr(str, '=') - str);
	if (ft_get_env_var_adress(data, var_check))
	{
		ft_update_env_var(data, var_check, str + ft_strlen(var_check) + 1);
		return (free(var_check), 0);
	}
	while (data->env[i])
		i++;
	new_env = (char **)ft_calloc(sizeof(char *), i + 2);
	if (!new_env)
		return (free(var_check), 1);
	i = -1;
	while (data->env[++i])
		new_env[i] = ft_strdup(data->env[i]);
	new_env[i++] = ft_strdup(str);
	ft_free_all(data->env, var_check);
	data->env = new_env;
	return (0);
}

/*
	Replace the value of the env variable `variable` by the string `new_val`
	@param t_data*data
	@param char*variable
	@param char*new_val
	@return void
*/
void	ft_update_env_var(t_data *data, char *variable, char *new_val)
{
	int		i;
	size_t	var_size;

	i = -1;
	var_size = ft_strlen(variable);
	while (data->env[++i])
	{
		if (!ft_strncmp(data->env[i], variable, var_size)
			&& data->env[i][var_size] == '=')
		{
			free(data->env[i]);
			data->env[i] = ft_strjoin_free(ft_strjoin(variable, "="), new_val);
			return ;
		}
	}
}

/*
	Deletes the variable `variable` from the `env` array
	in the `t_data` struct.
	@param t_data*data
	@param char*variable
	@return void
*/
void	ft_delete_env_var(t_data *data, char *variable)
{
	int				i;
	int				j;
	char			**new_env;
	size_t const	variable_len = ft_strlen(variable);

	i = 0;
	if (!ft_get_env_var_adress(data, variable))
		return ;
	while (data->env[i])
		i++;
	new_env = (char **)ft_calloc(sizeof(char *), i);
	if (!new_env)
		return ;
	i = -1;
	j = 0;
	while (data->env[++i])
	{
		if (!ft_strncmp(data->env[i], variable, variable_len)
			&& data->env[i][variable_len] == '=')
			continue ;
		new_env[j] = ft_strdup(data->env[i]);
		j++;
	}
	ft_free_array_str(data->env);
	data->env = new_env;
}
