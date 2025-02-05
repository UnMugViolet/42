/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:54:54 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/02/05 18:24:59 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_arrays_str(char **first, char **second)
{
	if (first)
		ft_free_array_str(first);
	if (second)
		ft_free_array_str(second);
}

void	ft_close_all(t_pipex pipex)
{
	if (pipex.in_fd != -1)
		close(pipex.in_fd);
	if (pipex.out_fd != -1)
		close(pipex.out_fd);
	if (pipex.pipefd[0] != -1)
		close(pipex.pipefd[0]);
	if (pipex.pipefd[1] != -1)
		close(pipex.pipefd[1]);
}

void	ft_exit_error(t_pipex pipex, char *str)
{
	perror(str);
	ft_close_all(pipex);
	if (pipex.current_cmd)
		ft_free_array_str(pipex.current_cmd);
	exit(EXIT_FAILURE);
}
