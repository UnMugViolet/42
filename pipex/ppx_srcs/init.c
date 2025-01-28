/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:06:25 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/01/28 17:11:59 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	is_struct_init(t_pipex pipex, int ac, char **av, char **env)
{
	pipex.in_fd = open(av[1], O_RDONLY);
	if (pipex.in_fd == -1)
		return (perror("Error opening file 1 : "), 0);
	pipex.out_fd = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT , 00400 | 00200);
	if (pipex.out_fd == -1)
		return (perror("Error opening file 2 : "), 0);
	if (pipe(pipex.pipefd) == -1)
		return (perror("Error creating pipe : "), 0);
	if (!ft_strncmp(av[1], "here_doc", 9))
		pipex.here_doc = 1;
	pipex.cmd_count = ac - 3;
	pipex.env = env;
	if (dup2(pipex.in_fd, STDIN_FILENO) == -1)
		return (perror("dup2 in : "), 0);
	if (dup2(pipex.out_fd, STDOUT_FILENO) == -1)
		return (perror("dup2 out : "), 0);
	ft_printf("Bonjour !\n");
	return (1);
}
