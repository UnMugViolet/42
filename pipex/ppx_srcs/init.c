/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:06:25 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/01/29 17:52:45 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_struct_init(t_pipex *pipex, int ac, char **av, char **env)
{
    pipex->in_fd = open(av[1], O_RDONLY);
    if (pipex->in_fd < 0)
        ft_exit_error(*pipex, "Error opening file 1");
    if (!ft_strncmp(av[1], "here_doc", 9))
        pipex->out_fd = open(av[ac - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
    else
        pipex->out_fd = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
    if (pipex->out_fd < 0)
        ft_exit_error(*pipex, "Error opening file 2");
    pipex->cmd_count = ac - 3;
    pipex->env = env;
    pipex->current_cmd = NULL;
}
