/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:44:49 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/01/28 19:23:34 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "ft_printf.h"
#include "libft.h"

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
	bool	here_doc;
}			t_pipex;

int		is_files_accessible(int ac, char **av);
void	exit_all(t_pipex *pipex);
bool	is_struct_init(t_pipex pipex, int ac, char **av, char **env);

#endif
