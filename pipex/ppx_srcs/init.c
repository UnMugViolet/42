/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:06:25 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/01/29 11:05:26 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Print the struct: 
// ft_printf(" in_fd = %i\n out_fd = %i\n pipefd[0] = %i pipefd[1] = %i\n cmd_count = %i\n", pipex.in_fd, pipex.out_fd, pipex.pipefd[0], pipex.pipefd[1], pipex.cmd_count);
bool	is_struct_init(t_pipex pipex, int ac, char **av, char **env)
{
    pipex.in_fd = open(av[1], O_RDONLY);
    if (pipex.in_fd == -1)
        return (perror("Error opening file 1 : "), 0);
    pipex.out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (pipex.out_fd == -1)
    {
        if (pipex.in_fd != -1)
            close(pipex.in_fd);
        return (perror("Error opening file 2 : "), exit(EXIT_FAILURE), 0);
    }
    if (pipe(pipex.pipefd) == -1)
        return (perror("Error creating pipe : "), 0);
    pipex.here_doc = 0;
    pipex.cmd_count = ac - 3;
    pipex.env = env;
    return (1);
}
