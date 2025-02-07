/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:43:22 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/02/07 14:50:34 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_get_path_for_command(t_pipex *pipex)
{
	int		i;
	char	*path;

	i = -1;
	while (pipex->paths[++i])
	{
		path = ft_strjoin(pipex->paths[i], pipex->current_cmd[0]);
		if (access(path, F_OK | X_OK) == 0)
		{
			pipex->cmd_path = path;
			return ;
		}
		free(path);
	}
	pipex->cmd_path = NULL;
}

void	ft_exec_child(t_pipex *pipex, int in_fd, int out_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_exit_error(pipex, "fork\n");
	if (pid == 0)
	{
		if (in_fd != STDIN_FILENO)
		{
			if (dup2(in_fd, STDIN_FILENO) == -1)
				in_fd = STDIN_FILENO;
			close(in_fd);
		}
		if (out_fd != STDOUT_FILENO)
		{
			if (dup2(out_fd, STDOUT_FILENO) == -1)
				ft_exit_error(pipex, "dup2 out\n");
			close(out_fd);
		}
		if (pipex->cmd_path)
			execve(pipex->cmd_path, pipex->current_cmd, pipex->env);
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(pipex->current_cmd[0], 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_heredoc(t_pipex *pipex, char *limiter)
{
	char	*line;
	size_t	limiter_len;

	limiter_len = ft_strlen(limiter);
	if (pipe(pipex->pipefd) == -1)
		ft_exit_error(pipex, "pipe error\n");
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
	int	i;

	ft_first_cmd(*pipex, &i);
	while (++i < ac - 2)
	{
		pipex->current_cmd = ft_split_quote(av[i], ' ', '\'');
		ft_get_path_for_command(pipex);
		if (pipe(pipex->pipefd) == -1)
			ft_exit_error(pipex, "pipe error\n");
		ft_exec_child(pipex, pipex->in_fd, pipex->pipefd[1]);
		wait(NULL);
		free(pipex->cmd_path);
		close(pipex->pipefd[1]);
		close(pipex->in_fd);
		pipex->in_fd = pipex->pipefd[0];
		ft_free_array_str(pipex->current_cmd);
	}
	pipex->current_cmd = ft_split_quote(av[i], ' ', '\'');
	ft_get_path_for_command(pipex);
	ft_exec_child(pipex, pipex->in_fd, pipex->out_fd);
	wait(NULL);
	free(pipex->cmd_path);
	ft_free_array_str(pipex->current_cmd);
	ft_close_all(pipex);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (!env[0])
		return (ft_putstr_fd("Env is missing\n", 2), EXIT_FAILURE);
	ft_arg_check(ac, av);
	ft_check_access(ac, av);
	ft_struct_init(&pipex, ac, av, env);
	if (pipex.here_doc)
		ft_heredoc(&pipex, av[2]);
	ft_exec_commands(&pipex, ac, av);
	ft_free_array_str(pipex.paths);
	return (EXIT_SUCCESS);
}
