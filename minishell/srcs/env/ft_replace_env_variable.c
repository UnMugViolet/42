/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_env_variable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:19:39 by fureimu           #+#    #+#             */
/*   Updated: 2025/04/08 10:31:28 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Utils function for `ft_get_new_size()` function. Frees the two strings
	given in arguments if not `NULL`.
	@param char*value
	@param char*name
	@return void
*/
static void	ft_double_free(char *value, char *name)
{
	if (value)
		free(value);
	if (name)
		free(name);
}

/*
	Returns the new size of the string `str` using the env values instead of
	their name (only if not in single quotes).
	@param t_data*data
	@param char*str
	@return size_t
*/
static size_t	ft_get_new_size(t_data *data, char *str)
{
	bool	in_sgl;
	char	*arr[2];
	size_t	size;

	if (!str)
		return (0);
	in_sgl = false;
	size = 0;
	while (*str)
	{
		if (*str == '\'')
			in_sgl =! in_sgl;
		if (*str == '$' && !in_sgl)
		{
			arr[0] = ft_get_env_var_name(str);
			arr[1] = ft_get_associated_env_value(data, arr[0]);
			size += ft_strlen(arr[1]);
			str += ft_strlen(arr[0]) + 1;
			ft_double_free(arr[1], arr[0]);
			continue ;
		}
		str++;
		size++;
	}
	return (size + 1);
}

/*
	Utils function for `ft_replace_if_not_in_sgl()` function. concatenates the
	value of the env var given in `str` to the string `res` , then moves the
	`res` pointer the size of the value further and moves the `str` pointer
	the size of the env var `name` further.
	@param t_data*data
	@param char**str
	@param char**res
*/
static void	ft_replace_and_advance(t_data *data, char **str, char **res)
{
	char	*value;
	char	*name;

	name = ft_get_env_var_name(*str);
	value = ft_get_associated_env_value(data, name);
	*str += ft_strlen(name) + 1;
	ft_strlcat(*res, value, ft_strlen(*res) + ft_strlen(value) + 1);
	*res += ft_strlen(value);
	free(value);
	free(name);
}

/*
	Returns a string with the env values instead of their name if they're not
	inside single quotes.
	@param t_data*data
	@param char*str
	@return char *
*/
static char	*ft_replace_if_not_in_sgl(t_data *data, char *str)
{
	char	*res;
	char	*start;
	bool	in_sgl;

	if (!str)
		return (NULL);
	res = (char *)ft_calloc(sizeof(char), ft_get_new_size(data, str) + 1);
	if (!res)
		return (NULL);
	in_sgl = false;
	start = res;
	while (*str)
	{
		if (*str == '\'')
			in_sgl = !in_sgl;
		if (*str == '$' && !in_sgl)
		{
			ft_replace_and_advance(data, &str, &res);
			continue ;
		}
		*res = *str;
		str++;
		res++;
	}
	return (start);
}

/*
	Browses the `cmd` array, replaces env variables by their values if not 
	inside signle quotes and removes pairs of matching quotes.
	@param t_data* data
	@return void
*/
void	ft_replace_env_variable(t_data *data)
{
	char	**cmd;
	char	*temp;
	int		i;

	i = 0;
	cmd = data->exec->cmd;
	while (cmd[i])
	{
		temp = ft_replace_if_not_in_sgl(data, cmd[i]);
		ft_remove_quotes_if_pair(temp);
		free(cmd[i]);
		cmd[i] = temp;
		i++;
	}
}
