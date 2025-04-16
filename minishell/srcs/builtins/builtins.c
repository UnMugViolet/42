/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:04:00 by fureimu           #+#    #+#             */
/*   Updated: 2025/04/16 10:00:21 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_print_export(char **env, char *str, int fd)
{
	int	i;

	i = 0;
	if (!env)
		return ;
	while (env[i])
	{
		ft_putstr_fd(str, fd);
		ft_putendl_fd(env[i], fd);
		i++;
	}
}
/*
	Contain the rules and functions for all the builtins executed in the
	parent process. It will also update the last exit value of the shell.
	@param	data
	@param	cmd
	@return	1 if a built-in command was executed, 0 otherwise.
*/
int	ft_exec_parent_builtins(t_data *data, char **cmd)
{
	if (!ft_strncmp(*cmd, "exit", 5))
		return (ft_exit(data, cmd), 1);
	else if (!ft_strncmp(*cmd, "cd", 3))
		return (ft_update_last_exit_value(data, ft_cd(data, cmd)), 1);
	else if (!ft_strncmp(*cmd, "export", 7))
		return (ft_print_export(data->env, "export ", STDOUT_FILENO), 1);
	else if (!ft_strncmp(*cmd, "export", 7) && cmd[1])
		return (ft_update_last_exit_value(data, ft_create_env_var(data,
					cmd[1])), 1);
	else if (!ft_strncmp(*cmd, "unset", 6) && cmd[1])
		return (ft_delete_env_var(data, cmd[1]), ft_update_last_exit_value(data,
				0), 1);
	return (0);
}

/*
	Contain the rules and functions for all the builtins executed in the
	child process. It will also update the last exit value of the shell.
	@param	data
	@param	cmd
	@return	1 if a built-in command was executed, 0 otherwise.
*/
int	ft_exec_child_builtins(t_data *data, char **cmd)
{
	if (!ft_strncmp(*cmd, "pwd", 4))
		return (ft_putendl_fd(ft_get_env_var_adress(data, "PWD") + 4,
				STDOUT_FILENO), ft_update_last_exit_value(data, 0), 1);
	else if (!ft_strncmp(*cmd, "echo", 5))
		return (ft_echo(cmd), ft_update_last_exit_value(data, 0), 1);
	else if (!ft_strncmp(*cmd, "env", 4) && !cmd[1])
		return (ft_print_array_str_fd(data->env, STDOUT_FILENO),
			ft_update_last_exit_value(data, 0), 1);
	return (0);
}
