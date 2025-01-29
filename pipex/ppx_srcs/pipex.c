/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:43:22 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/01/29 18:23:25 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_child(t_pipex *pipex, int in_fd, int out_fd, char *command)
{
	pid_t		pid;

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
		perror("Exec");
		exit(EXIT_FAILURE);
	}
}

void	ft_exec_commands(t_pipex *pipex, int ac, char **av)
{
	int		i;
	char	*str;

	i = 1;
	while (++i < ac - 2)
	{
		pipex->current_cmd = ft_split(av[i], ' ');
		ft_printf("I value: %i\nString %s\n",i,  pipex->current_cmd[0]);
		str = ft_strjoin("/bin/", pipex->current_cmd[0]);
		if (pipe(pipex->pipefd) == -1)
			ft_exit_error(*pipex, "pipe error");
		ft_exec_child(pipex, pipex->in_fd, pipex->pipefd[1], str);
		close(pipex->pipefd[1]);
		close(pipex->in_fd);
		pipex->in_fd = pipex->pipefd[0];
		ft_free_split(pipex->current_cmd);
		free(str);
	}
	str = ft_strjoin("/bin/", pipex->current_cmd[0]);
	pipex->current_cmd = ft_split(av[i], ' ');
	ft_exec_child(pipex, pipex->in_fd, pipex->out_fd, str);
	ft_free_split(pipex->current_cmd);
	ft_close_all(*pipex, str);
	i = 1;
	while (++i < ac - 1)
		wait(NULL);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac < 5)
		return (ft_putstr_fd("Not enough arguments.\n", 2), EXIT_FAILURE);
	ft_check_access(ac, av);
	ft_struct_init(&pipex, ac, av, env);
	ft_exec_commands(&pipex, ac, av);
	return (EXIT_SUCCESS);
}
