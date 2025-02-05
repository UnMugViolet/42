/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:06:25 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/02/05 18:24:59 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_get_paths_from_env(t_pipex *pipex, char **env)
{
	int		i;

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
	if (!ft_strncmp(av[1], "here_doc", 9))
	{
		pipex->in_fd = STDIN_FILENO;
		pipex->here_doc = 1;
		pipex->out_fd = open(av[ac - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
		if (pipex->out_fd == -1)
			ft_exit_error(*pipex, "Error opening file 2");
	}
	else
	{
		pipex->in_fd = open(av[1], O_RDONLY);
		pipex->here_doc = 0;
		pipex->out_fd = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
		if (pipex->out_fd == -1)
			ft_exit_error(*pipex, "Error opening file 2");
	}
	ft_get_paths_from_env(pipex, env);
	pipex->env = env;
	pipex->cmd_count = ac - 3;
	pipex->current_cmd = NULL;
}

void	ft_first_cmd(t_pipex pipex, int *i)
{
	*i = 1 + pipex.here_doc;
	if (pipex.in_fd < 0)
		*i = 2;
}

void	ft_cmd_paths(t_pipex *pipex)
{
	int	i;
	char **cmd;

	i = 0;
	while (pipex->paths[i])
		i++;
	cmd = (char **)ft_calloc(sizeof(char *), i);
	if (!cmd)
		exit (EXIT_FAILURE);
	i = 0;
	while (pipex->paths[i])
	{
		cmd[i] = ft_strjoin(pipex->paths[i], pipex->current_cmd[0]);
		if (!cmd[i])
		{
			ft_free_array_str(cmd);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	cmd[i] = 0;
	pipex->paths_cmd = cmd;
}

void	ft_init_cmd(t_pipex *pipex, char *cmd)
{
	pipex->current_cmd = ft_split_quote(cmd, ' ', '\'');
	ft_cmd_paths(pipex);
}
