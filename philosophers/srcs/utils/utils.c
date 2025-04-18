/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:22:09 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/18 10:09:30 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		ft_putstr_fd("Error: gettimeofday()\n", ERR_OUT);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

void	ft_usleep(size_t ms)
{
	size_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start ) < ms)
		usleep(500);
}

void	ft_destroy_all(t_prog *program, pthread_mutex_t *forks, char *str)
{
	size_t	i;

	i = 0;
	if (str)
		ft_putstr_fd(str, ERR_OUT);
	while (i < program->philos[0].nb_philo)
		pthread_mutex_destroy(&forks[i++]);
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
}

void	print_usage(void)
{
	ft_putstr_fd(ERR_USAGE, STDOUT_FILENO);
}
