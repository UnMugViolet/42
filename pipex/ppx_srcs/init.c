/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:06:25 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/01/29 14:09:48 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Print the struct: 
// ft_printf(" in_fd = %i\n out_fd = %i\n pipefd[0] = %i pipefd[1] = %i\n cmd_count = %i\n", pipex.in_fd, pipex.out_fd, pipex.pipefd[0], pipex.pipefd[1], pipex.cmd_count);
void	ft_struct_init(t_pipex pipex, int ac, char **av, char **env)
{
	pipex.in_fd = open(av[1], O_RDONLY);
	if (pipex.in_fd == -1)
		ft_exit_error(pipex, "Error opening file 1");
	if (!ft_strncmp(av[1], "here_doc", 9))
		pipex.out_fd = open(av[ac - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
	else
		pipex.out_fd = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pipex.out_fd == -1)
		ft_exit_error(pipex, "Error opening file 2");
	if (pipe(pipex.pipefd) == -1)
		ft_exit_error(pipex, "Error creating pipe");
	pipex.cmd_count = ac - 3;
	pipex.env = env;
	if (dup2(pipex.in_fd, STDIN_FILENO) == -1)
		ft_exit_error(pipex, "dup2 in");
	if (dup2(pipex.out_fd, STDOUT_FILENO) == -1)
		ft_exit_error(pipex, "dup2 out");
	pipex.processes = (pid_t *)ft_calloc(pipex.cmd_count, sizeof(pid_t));
	if (!pipex.processes)
		ft_exit_error(pipex, "Calloc processes");
	pipex.current_cmd = NULL;
}
