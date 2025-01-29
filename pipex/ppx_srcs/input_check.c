/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:06:47 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/01/28 19:23:53 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_files_accessible(int ac, char **av)
{
	if (access(av[1], R_OK) == -1)
		return (perror("Error file 1 : "), 0);
	if (access(av[ac - 1], F_OK) == -1)
		return (2);
	if (access(av[ac - 1], R_OK | W_OK) == -1)
		return (perror("Error file 2 : "), 0);
	return (1);
}
