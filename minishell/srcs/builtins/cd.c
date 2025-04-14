/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:04:00 by fureimu           #+#    #+#             */
/*   Updated: 2025/04/10 10:46:11 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Created to make the function ft_cd more readable, this function update the
	the environment variables `PWD` and `OLDPWD` with the new directory, and free
	the `curr_dir` and `new_dir` variables.
	@param t_data*data
	@param char*curr_dir
	@param char*new_dir
	@return void
*/
static void	ft_update_env_and_free(t_data *data, char *curr_dir, char *new_dir)
{
	ft_update_env_var(data, "PWD", new_dir);
	ft_update_env_var(data, "OLDPWD", curr_dir);
	free(curr_dir);
	free(new_dir);
}

/* 
	Utilitary function to update the environment variables `PWD` and `OLDPWD`
	after a successful change of directory. It update the env variables with the
	`new_dir` variables.
	@param t_data*data
	@param char*path
*/
static int	ft_change_dir(t_data *data, char *path)
{
	bool	is_env_var;
	char	*curr_dir;
	char	*new_dir;

	new_dir = path;
	is_env_var = false;
	curr_dir = getcwd(NULL, 0);
	if (!curr_dir)
		return (perror("cd"), ft_update_last_exit_value(data, 1), 1);
	if (!ft_strncmp(path, "-", 2))
	{
		new_dir = ft_get_associated_env_value(data, "OLDPWD");
		is_env_var = true;
	}
	if (!ft_strncmp(path, "~", 2))
	{
		new_dir = ft_get_associated_env_value(data, "HOME");
		is_env_var = true;
	}
	if (chdir(new_dir) == -1)
		return (perror("cd"), free(curr_dir), 1);
	if (is_env_var)
		free(new_dir);
	new_dir = getcwd(NULL, 0);
	return (ft_update_env_and_free(data, curr_dir, new_dir), 0);
}

/*
	Change the current working directory to the one specified in `cmd[1]`.
	If no argument is given, change to the home directory.
	If the argument is `-`, change to the previous directory.
	If the argument is `~`, change to the home directory.
	If the argument is not a valid path, print an error message and return 1.
	@param t_data*data
	@param char**cmd
	@return int
*/
int	ft_cd(t_data *data, char **cmd)
{
	char		*path;
	struct stat	sb;

	if (!cmd[1])
	{
		path = ft_get_associated_env_value(data, "HOME");
		if (ft_strlen(path) == 0)
			return (free(path), ft_putstr_fd("cd: HOME not set\n",
					ERR_OUT), 1);
		return (ft_change_dir(data, path), free(path), 0);
	}
	else
		path = cmd[1];
	if (cmd[1] && cmd[2])
		return (ft_putstr_fd("cd: too many arguments\n", ERR_OUT), 1);
	else if (stat(path, &sb) == -1 && ft_strncmp(path, "-", 2)
		&& ft_strncmp(path, "~", 2))
		return (perror("cd"), 1);
	else
		return (ft_update_last_exit_value(data, 0), ft_change_dir(data, path));
}
