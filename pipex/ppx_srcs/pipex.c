/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:43:22 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/01/28 19:21:39 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac < 5)
		return (ft_putstr_fd("Wrong number of args.", 2), EXIT_FAILURE);
	if (!is_struct_init(pipex, ac, av, env))
		return (EXIT_FAILURE);
    return (0);
}
