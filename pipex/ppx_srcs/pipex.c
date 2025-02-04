/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:43:22 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/02/04 18:43:55 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_child(t_pipex *pipex, int in_fd, int out_fd, char *command)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_exit_error(*pipex, "fork");
	if (pid == 0)
	{
		if (in_fd != STDIN_FILENO)
		{
			if (dup2(in_fd, STDIN_FILENO) == -1)
				ft_exit_error(*pipex, "dup2 in");
			close(in_fd);
		}
		if (out_fd != STDOUT_FILENO)
		{
			if (dup2(out_fd, STDOUT_FILENO) == -1)
				ft_exit_error(*pipex, "dup2 out");
			close(out_fd);
		}
		execve(command, pipex->current_cmd, pipex->env);
		perror(command);
		exit(EXIT_FAILURE);
	}
}

void	ft_heredoc(t_pipex *pipex, char *limiter)
{
	char	*line;
	size_t	limiter_len;

	limiter_len = ft_strlen(limiter);
	if (pipe(pipex->pipefd) == -1)
		ft_exit_error(*pipex, "pipe error");
	while (true)
	{
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(0);
		if (!line || (!ft_strncmp(line, limiter, limiter_len)
				&& line[limiter_len] == '\n'))
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, pipex->pipefd[1]);
		free(line);
	}
	close(pipex->pipefd[1]);
	pipex->in_fd = pipex->pipefd[0];
}

void	ft_exec_commands(t_pipex *pipex, int ac, char **av)
{
	int		i;
	char	*command;

	ft_first_cmd(*pipex, &i);
	while (++i < ac - 2)
	{
		pipex->current_cmd = ft_split_quote(av[i], ' ', '\'');
		command = ft_command_path(pipex->current_cmd[0]);
		if (pipe(pipex->pipefd) == -1)
			ft_exit_error(*pipex, "pipe error");
		ft_exec_child(pipex, pipex->in_fd, pipex->pipefd[1], command);
		close(pipex->pipefd[1]);
		close(pipex->in_fd);
		pipex->in_fd = pipex->pipefd[0];
		ft_free_split(pipex->current_cmd);
		free(command);
	}
	pipex->current_cmd = ft_split_quote(av[i], ' ', '\'');
	command = ft_command_path(pipex->current_cmd[0]);
	ft_exec_child(pipex, pipex->in_fd, pipex->out_fd, command);
	ft_free_split(pipex->current_cmd);
	i = 1;
	while (++i < ac - 1)
		wait(NULL);
	ft_close_all(*pipex, command);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	ft_arg_check(ac, av);
	ft_check_access(ac, av);
	ft_struct_init(&pipex, ac, av, env);
	if (pipex.here_doc)
		ft_heredoc(&pipex, av[2]);
	ft_exec_commands(&pipex, ac, av);
	return (EXIT_SUCCESS);
}
