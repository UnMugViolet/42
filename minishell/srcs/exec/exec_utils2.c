/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:09:44 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/11 18:20:29 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_print_fd(int fd)
{
	if (fd == -1)
		ft_fprintf(ERR_OUT, STDRD_ERR_SINGLE, strerror(errno));
}

static int	hd_err(t_data *data, char *line, char *limiter, size_t limiter_len)
{
	if (!line)
	{
		close(data->pipe_fd[0]);
		close(data->pipe_fd[1]);
		return (ft_fprintf(1, EOF_HD_ERR, limiter), 1);
	}
	else if ((!ft_strncmp(line, limiter, limiter_len)
			&& line[limiter_len] == '\n'))
		return (free(line), 1);
	return (0);
}

/*
	Bulk wait for all the child processes to finish and update the last exit
	value of the shell env. The waiting is done in a loop and checks the
	`pid_list` to get all the pids.
	@param t_data*data
	@return void
*/
void	ft_wait_and_update_status(t_data *data)
{
	int	i;
	int	status;

	i = 0;
	while (i < data->pid_count)
	{
		if (waitpid(data->pid_list[i], &status, 0) == -1)
			ft_exit_clean(data, ft_fprintf(ERR_OUT, STDRD_ERR_SINGLE,
					strerror(errno)), false);
		ft_update_last_exit_value(data, WEXITSTATUS(status));
		i++;
	}
}

/*
	Handle the `heredoc` redirection. The function will create a pipe and
	write the input from the user to the pipe until the user enters
	the `limiter` string. The pipe is then closed and the `in_fd` of
	the next command is set to the read end of the pipe.
	@param t_data*data
	@param t_exec*exec
	@param char* limiter
	@return void
*/
int	ft_exec_heredoc(t_data *data, t_exec *exec, char *limiter)
{
	int				return_value;	
	char			*line;
	size_t const	limiter_len = ft_strlen(limiter);

	g_sigint_received = 0;
	if (data->pipe_fd[0] != -1)
		close(data->pipe_fd[0]);
	if (pipe(data->pipe_fd) == -1)
		ft_fprintf(ERR_OUT, STDRD_ERR_SINGLE, strerror(errno));
	while (!g_sigint_received)
	{
		ft_fprintf(1, "heredoc> ");
		line = get_next_line(0);
		return_value = hd_err(data, line, limiter, limiter_len);
		if (return_value)
			break ;
		ft_putstr_fd(line, data->pipe_fd[1]);
		free(line);
	}
	close(data->pipe_fd[1]);
	if (ft_get_next_word(exec))
		ft_get_next_word(exec)->in_fd = data->pipe_fd[0];
	return (return_value);
}
// Tu t'emmerdes pour rien la !!
// Moi j'aurais pas fait comme ca !
