/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:44:50 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/02/04 19:34:25 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_command_path(char *cmd)
{
	char *const	which_cmd[3] = {"which", cmd, NULL};
	pid_t		child;
	char		*path;
	int			pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		perror("fork command path");
	child = fork();
	if (child == -1)
		perror("fork command path");
	if (child == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		execve("/usr/bin/which", which_cmd, NULL);
	}
	wait(NULL);
	path = get_next_line(pipe_fd[0]);
	if (path[ft_strlen(path) - 1] == '\n')
		path = ft_substr_free(path, 0, ft_strlen(path) - 1);
	return (path);
}
