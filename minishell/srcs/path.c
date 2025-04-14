/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:18:56 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/04/09 13:10:25 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_default_path(t_data *data, char ***paths)
{
	int	i;

	i = 0;
	while (data->env[i] && ft_strncmp(data->env[i], "PATH=", 5))
		i++;
	if (data->env[i] && !ft_strncmp(data->env[i], "PATH=", 5))
		*paths = ft_split(data->env[i] + 5, ':');
}

/*
	Fetches the `$PATH` value from the `data->env` array.
	If no `$PATH` is found, sets the value to `DEF_PATH` if the `get_default` is
	set to `true`. Otherwise returns `NULL`.
	@param t_data*data
	@param bool get_default
	@return char *
*/
char	**ft_get_path_from_env(t_data *data, bool get_default)
{
	int		i;
	char	**paths;
	char	*env_var;

	i = -1;
	paths = NULL;
	if (data->env && *data->env)
		get_default_path(data, &paths);
	if (!paths && get_default)
	{
		paths = ft_split(DEF_PATH, ':');
		env_var = ft_strjoin("PATH=", DEF_PATH);
		if (!env_var)
			return (NULL);
		ft_create_env_var(data, env_var);
		free(env_var);
	}
	if (!paths)
		return (NULL);
	while (paths[++i])
		paths[i] = ft_strjoin_free(paths[i], "/");
	return (paths);
}

/*
	Parse the paths given from the `data` struc and return the concatenation of
	the path and the `cmd`.
	If the `cmd` is given with a path (e.g. /bin/ls),
		return the `cmd` if accessed.
	@param t_data *data
	@param char* cmd
	@return char *full_cmd or NULL
*/
char	*ft_get_path_for_cmd(t_data *data, char *cmd)
{
	size_t	i;
	char	*full_cmd;

	i = 0;
	full_cmd = NULL;
	if (!cmd || !data->paths)
		return (ft_strdup(""));
	if (access(cmd, F_OK) == 0)
		return (ft_strdup(cmd));
	else
	{
		while (data->paths[i])
		{
			full_cmd = ft_strjoin(data->paths[i], cmd);
			if (!full_cmd)
				return (ft_exit_error(data, MALLOC_ERROR, ERR_OUT), NULL);
			if (access(full_cmd, F_OK) == 0)
				return (full_cmd);
			free(full_cmd);
			i++;
		}
	}
	return (ft_strdup(""));
}
