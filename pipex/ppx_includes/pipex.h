/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:44:49 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/01/29 14:32:36 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"

# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		pipefd[2];
	int		cmd_count;
	char	**env;
	char	**current_cmd;
	pid_t	*processes;
}			t_pipex;

void	ft_check_access(int ac, char **av);
void	ft_struct_init(t_pipex pipex, int ac, char **av, char **env);
void	ft_exit_error(t_pipex pipex, char *str);

#endif
