/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:44:49 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/01/29 18:21:03 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"

# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		cmd_count;
	int		pipefd[2];
	char	**env;
	char	**current_cmd;
}			t_pipex;

void	ft_check_access(int ac, char **av);
void	ft_struct_init(t_pipex *pipex, int ac, char **av, char **env);
void	ft_exit_error(t_pipex pipex, char *str);
void	ft_close_all(t_pipex pipex, char *curr_str);

#endif

