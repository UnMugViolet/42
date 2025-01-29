/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:43:22 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/01/29 14:32:16 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	int		i;

	ft_printf("%p\n", &pipex);
	printf("%p\n", &pipex);
	return (1);
	if (ac < 5)
		return (ft_putstr_fd("Wrong number of args.", 2), EXIT_FAILURE);
	ft_check_access(ac, av);
	ft_struct_init(pipex, ac, av, env);
	i = 0;
	dup2(pipex.pipefd[0], pipex.in_fd);
	while (i < pipex.cmd_count - 1)
	{
		pipex.current_cmd = ft_split(av[i + 2], ' ');
		if (!pipex.current_cmd)
			ft_exit_error(pipex, "Split");
		pipex.processes[i] = fork();
		if (pipex.processes[i] == -1)
			ft_exit_error(pipex, "Fork");
		if (pipex.processes[i] == 0)
			execve(pipex.current_cmd[0], pipex.current_cmd, pipex.env);
		i++;
	}
	if (pipex.processes[0] == 0)
	{
		dup2(STDIN_FILENO, pipex.pipefd[0]);
		dup2(pipex.pipefd[1], STDOUT_FILENO);
	}
	return (EXIT_SUCCESS);
}
