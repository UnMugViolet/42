/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:22:09 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/16 15:59:37 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		ft_putstr_fd("Error: gettimeofday()\n", ERR_OUT);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(size_t ms)
{
	size_t	start;

	start = ft_get_time();
	while (ft_get_time() - start < ms)
		usleep(500);
}

void	print_usage(void)
{
	ft_putstr_fd(ERR_USAGE, ERR_OUT);
}
