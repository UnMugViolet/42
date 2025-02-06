/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:54:54 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/02/06 16:01:21 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_all(t_pipex *pipex)
{
	if (pipex->in_fd != -1)
		close(pipex->in_fd);
	if (pipex->out_fd != -1)
		close(pipex->out_fd);
	if (pipex->pipefd[0] != -1 && pipex->pipefd[0] != pipex->in_fd)
		close(pipex->pipefd[0]);
	if (pipex->pipefd[1] != -1 && pipex->pipefd[1] != pipex->out_fd)
		close(pipex->pipefd[1]);
}

void	ft_exit_error(t_pipex *pipex, char *str)
{
	ft_putstr_fd(str, 2);
	ft_close_all(pipex);
	if (pipex->current_cmd)
		ft_free_array_str(pipex->current_cmd);
	if (pipex->paths)
		ft_free_array_str(pipex->paths);
	exit(EXIT_FAILURE);
}
