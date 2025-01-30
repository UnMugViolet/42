/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:06:47 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/01/30 14:37:27 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_access(int ac, char **av)
{
	if (access(av[1], R_OK) == -1 && ft_strncmp(av[1], "here_doc", 9) != 0)
	{
		perror("Error file 1");
		exit(EXIT_FAILURE);
	}
	if (access(av[ac - 1], F_OK) == -1)
		return ;
	if (access(av[ac - 1], R_OK | W_OK) == -1)
	{
		perror("Error file 2");
		exit(EXIT_FAILURE);
	}
}
