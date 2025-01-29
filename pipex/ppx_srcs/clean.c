/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:54:54 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/01/29 14:31:26 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit_error(t_pipex pipex, char *str)
{
	perror(str);
	if (pipex.in_fd != -1)
		close(pipex.in_fd);
	if (pipex.out_fd != -1)
		close(pipex.out_fd);
	if (pipex.pipefd[0] != -1)
		close(pipex.pipefd[0]);
	if (pipex.pipefd[1] != -1)
		close(pipex.pipefd[1]);
	if (pipex.processes)
		free(pipex.processes);
	if (pipex.current_cmd)
		ft_free_split(pipex.current_cmd);
	exit(EXIT_FAILURE);
}
