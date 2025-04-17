/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:16:42 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/17 18:56:07 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

static bool	ft_is_dead_flag(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead)
		return (pthread_mutex_unlock(philo->dead_lock), true);
	return (pthread_mutex_unlock(philo->dead_lock), false);
}

static void	*start_routine(void *ptr)
{
	t_philo	*philo;
	
	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!ft_is_dead_flag(philo))
	{
		ft_eat(philo);
		ft_dream(philo);
		ft_think(philo);
	}
	return (ptr);
}

int	ft_create_threads(t_prog *program, pthread_mutex_t *forks)
{
	pthread_t	observer;
	size_t	i;

	i = 0;

	if (pthread_create(&observer, NULL, &monitor_philos, program) != 0)
		ft_destroy_all(program, forks, ERR_CREATE_THREAD);
	while (i < program->philos[0].nb_philo)
	{
		if (pthread_create(&program->philos[i].thread, NULL,
				&start_routine, &program->philos[i]) != 0)
			return (ft_destroy_all(program, forks, ERR_CREATE_THREAD), -1);
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)
		return (ft_destroy_all(program, forks, ERR_JOIN_THREAD), -1);
	while (i < program->philos[0].nb_philo)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			return (ft_destroy_all(program, forks, ERR_JOIN_THREAD), -1);
		i++;
	}
	return (0);
}
