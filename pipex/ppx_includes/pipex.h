/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:44:49 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/02/06 16:01:16 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		cmd_count;
	int		pipefd[2];
	int		here_doc;
	char	**env;
	char	**paths;
	char	*cmd_path;
	char	**current_cmd;
}			t_pipex;

void	ft_first_cmd(t_pipex pipex, int *i);
void	ft_arg_check(int ac, char **av);
void	ft_check_access(int ac, char **av);
void	ft_get_paths_from_env(t_pipex *pipex, char **env);
void	ft_struct_init(t_pipex *pipex, int ac, char **av, char **env);
void	ft_exit_error(t_pipex *pipex, char *str);
void	ft_close_all(t_pipex *pipex);

#endif
