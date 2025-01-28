/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:00:29 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/01/28 19:01:07 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	is_struct_init(t_pipex pipex, int ac, char **av, char **env)
{
	pipex.in_fd = open(av[1], O_RDONLY);
	if (pipex.in_fd == -1)
		return (perror("Error opening file 1 : "), 0);
	pipex.out_fd = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (pipex.out_fd == -1)
	{
		if (pipex.in_fd != -1)
			close(pipex.in_fd);
		return (perror("Error opening file 2 : "), exit(EXIT_FAILURE), 0);
	}
	if (pipe(pipex.pipefd) == -1)
		return (perror("Error creating pipe : "), 0);
	if (!ft_strncmp(av[1], "here_doc", 9))
		pipex.here_doc = 1;
	pipex.cmd_count = ac - 3;
	pipex.env = env;
	return (1);
}
