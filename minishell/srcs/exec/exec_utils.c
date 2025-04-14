/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:11:18 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/04/11 18:47:21 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_attach_fd_to_exec(int fd, t_exec *exec)
{
	if (exec->next)
	{
		if (exec->type == RIGHT_BRACKET || exec->type == DBL_RIGHT_BRACKET)
			exec->next->out_fd = fd;
		else if (exec->type == LEFT_BRACKET)
			ft_get_next_word(exec)->in_fd = fd;
	}
}

/*
	Created to make the function exec child more readable, this function
	duplicates the file descriptor `fd` to `fd2` and closes `fd`.
	@param t_data*data
	@param int fd
	@param int fd2
	@return void
*/
void	ft_dup(t_data *data, int fd, int fd2)
{
	if (dup2(fd, fd2) == -1)
		ft_exit_clean(data, ft_fprintf(ERR_OUT, STDRD_ERR_SINGLE,
				strerror(errno)), false);
	close(fd);
}

/*
	Tiny utilitary function to handle the errors of the command. Depending on
	the error, it will print the error message and return the exit code.
	That exit code is used to update the last exit value of the shell env.
	@param t_exec*exec
	@return int
*/
static int	ft_handle_cmd_errors(t_exec *exec)
{
	if (errno == ENOENT)
		return (ft_fprintf(ERR_OUT, CMD_NOT_FOUND, exec->cmd[0]), 127);
	else if (errno == EACCES)
		return (ft_fprintf(ERR_OUT, PERM_DENIED, exec->cmd[0]), 126);
	else
		return (ft_fprintf(ERR_OUT, STDRD_ERR, exec->cmd[0], strerror(errno)),
			2);
}

/*
	Will execute all the commands in parallel, in case of redirection the
	`in_fd` and `out_fd` will be set to the file descriptor of the file.
	In case of pipe, the `in_fd` will be set to the read end of the pipe and
	the `out_fd` will be set to the write end of the pipe.
	@param t_data*data
	@param t_exec*exec
	@param pid_t*pid
	@param int is_pipe
	@return void
*/
void	ft_exec_child(t_data *data, t_exec *exec, pid_t *pid, int is_pipe)
{
	*pid = fork();
	if (*pid == -1)
		ft_exit_clean(data, ft_fprintf(ERR_OUT, STDRD_ERR_SINGLE,
				strerror(errno)), false);
	else if (*pid == 0)
	{
		if (exec->in_fd != STDIN_FILENO)
			ft_dup(data, exec->in_fd, STDIN_FILENO);
		if (exec->out_fd != STDOUT_FILENO)
			ft_dup(data, exec->out_fd, STDOUT_FILENO);
		if (is_pipe && exec->out_fd == STDOUT_FILENO)
		{
			close(data->pipe_fd[0]);
			ft_dup(data, data->pipe_fd[1], STDOUT_FILENO);
		}
		if (ft_is_builtin(exec->cmd[0]))
		{
			ft_exec_child_builtins(data, exec->cmd);
			ft_exit_clean(data, 0, false);
		}
		if (execve(exec->full_cmd, exec->cmd, data->env) == -1)
			ft_exit_clean(data, ft_handle_cmd_errors(exec), false);
	}
	else
		data->pid_list[data->pid_count++] = *pid;
}

/*
	Store all the redirections from `>` `<` `>>` `<<` get the file descriptor
	from exec command, open the file and add the fd of the file in `exec` struct
	of the command.
	This function is called everytime and executed only if the `type` is
	`RIGHT_BRACKET` or `LEFT_BRACKET`.
	@param t_exec*exec
	@param t_data*data
	@return void
*/
int	ft_handle_redirection(t_data *data, t_exec *exec)
{
	int	fd;

	if (exec->type == RIGHT_BRACKET)
	{
		fd = open(exec->cmd[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		ft_check_print_fd(fd);
		ft_attach_fd_to_exec(fd, exec);
	}
	else if (exec->type == LEFT_BRACKET)
	{
		fd = open(exec->cmd[1], O_RDONLY);
		ft_check_print_fd(fd);
		ft_attach_fd_to_exec(fd, exec);
	}
	else if (exec->type == DBL_RIGHT_BRACKET)
	{
		fd = open(exec->cmd[1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		ft_check_print_fd(fd);
		ft_attach_fd_to_exec(fd, exec);
	}
	else if (exec->type == DBL_LEFT_BRACKET)
		return (ft_exec_heredoc(data, exec, exec->cmd[1]));
	return (0);
}
