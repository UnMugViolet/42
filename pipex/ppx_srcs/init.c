/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:06:25 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/02/06 15:20:06 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_default_struct_init(t_pipex *pipex, int ac, char **env)
{
	pipex->in_fd = -1;
	pipex->out_fd = -1;
	pipex->pipefd[0] = -1;
	pipex->pipefd[1] = -1;
	pipex->env = env;
	pipex->cmd_count = ac - 3;
	pipex->here_doc = 0;
	pipex->paths = NULL;
	pipex->cmd_path = NULL;
	pipex->current_cmd = NULL;
	ft_get_paths_from_env(pipex, env);
}

void	ft_get_paths_from_env(t_pipex *pipex, char **env)
{
	int	i;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	pipex->paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (pipex->paths[++i])
		pipex->paths[i] = ft_strjoin_free(pipex->paths[i], "/");
}

void	ft_struct_init(t_pipex *pipex, int ac, char **av, char **env)
{
	ft_default_struct_init(pipex, ac, env);
	if (!ft_strncmp(av[1], "here_doc", 9))
	{
		pipex->in_fd = STDIN_FILENO;
		pipex->here_doc = 1;
		pipex->out_fd = open(av[ac - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
	}
	else
	{
		pipex->in_fd = open(av[1], O_RDONLY);
		pipex->out_fd = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	}
}

void	ft_first_cmd(t_pipex pipex, int *i)
{
	*i = 1 + pipex.here_doc;
	if (pipex.in_fd < 0)
		*i = 2;
}
