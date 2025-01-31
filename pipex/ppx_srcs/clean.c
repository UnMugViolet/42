/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:54:54 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/01/31 15:25:48 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_all(t_pipex pipex, char *curr_str)
{
	if (pipex.in_fd != -1)
		close(pipex.in_fd);
	if (pipex.out_fd != -1)
		close(pipex.out_fd);
	if (pipex.pipefd[0] != -1)
		close(pipex.pipefd[0]);
	if (pipex.pipefd[1] != -1)
		close(pipex.pipefd[1]);
	if (curr_str)
		free(curr_str);
}

void	ft_exit_error(t_pipex pipex, char *str)
{
	int	i;
	
	perror(str);
	ft_close_all(pipex, NULL);
	for (i = 0; pipex.current_cmd[i]; i++)
		ft_printf("%s\n", pipex.current_cmd[i]);
	if (pipex.current_cmd)
		ft_free_split(pipex.current_cmd);
	exit(EXIT_FAILURE);
}
