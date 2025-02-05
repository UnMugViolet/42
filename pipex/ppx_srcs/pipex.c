/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:43:22 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/02/05 18:35:31 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_child(t_pipex *pipex, int in_fd, int out_fd)
{
	pid_t	pid;
	int		i;

	i = -1;
	pid = fork();
	if (pid < 0)
		ft_exit_error(*pipex, "fork");
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
			{
				ft_exit_error(*pipex, "dup2 out");
			}
			close(out_fd);
		}
		while (pipex->paths_cmd[++i])
			execve(pipex->paths_cmd[i], pipex->current_cmd, pipex->env);
		perror(pipex->current_cmd[0]);
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

	ft_first_cmd(*pipex, &i);
	while (++i < ac - 2)
	{
		ft_init_cmd(pipex, av[i]);
		if (pipe(pipex->pipefd) == -1)
			ft_exit_error(*pipex, "pipe error");
		ft_exec_child(pipex, pipex->in_fd, pipex->pipefd[1]);
		close(pipex->pipefd[1]);
		close(pipex->in_fd);
		pipex->in_fd = pipex->pipefd[0];
		ft_free_array_str(pipex->current_cmd);
		ft_free_array_str(pipex->paths_cmd);
	}
	ft_init_cmd(pipex, av[i]);
	ft_exec_child(pipex, pipex->in_fd, pipex->out_fd);
	ft_free_array_str(pipex->current_cmd);
	ft_free_array_str(pipex->paths_cmd);
	i = 1;
	while (++i < ac - 1)
		wait(NULL);
	ft_close_all(*pipex);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (!env)
		return (ft_putstr_fd("Env is missing\n",2), EXIT_FAILURE);
	ft_arg_check(ac, av);
	ft_check_access(ac, av);
	ft_struct_init(&pipex, ac, av, env);
	if (pipex.here_doc)
		ft_heredoc(&pipex, av[2]);
	ft_exec_commands(&pipex, ac, av);
	ft_free_array_str(pipex.paths);
	return (EXIT_SUCCESS);
}
