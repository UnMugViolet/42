/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:54:54 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/01/28 19:01:12 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_all(t_pipex *pipex)
{
	if (pipex->in_fd != -1)
		close(pipex->in_fd);
	if (pipex->out_fd != -1)
		close(pipex->out_fd);
	if (pipex->pipefd[0] != -1)
		close(pipex->pipefd[0]);
	if (pipex->pipefd[1] != -1)
		close(pipex->pipefd[1]);
	exit(EXIT_FAILURE);
}
