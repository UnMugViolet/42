/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:16:42 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/22 09:50:07 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

/*
	Checks if the philosopher is dead by checking the dead flag.
	Dead flag is a boolean value that is set to true by the function
	`ft_is_any_philo_dead`.
	@param philo: the philosopher structure
	@return: true if the philosopher is dead, false otherwise
*/
bool	ft_is_dead_flag(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead)
		return (pthread_mutex_unlock(philo->dead_lock), true);
	return (pthread_mutex_unlock(philo->dead_lock), false);
}

/*
	Routine for the philosopher threads.
	Each philosopher will eat, sleep and think in a loop.
	The loop will break if the philosopher is dead.
	@param ptr: the philosopher structure
	@return: the philosopher structure
*/
static void	*start_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(philo->time_to_eat / 2);
	while (true)
	{
		if (ft_is_dead_flag(philo))
			break;
		ft_eat(philo);
		if (ft_is_dead_flag(philo))
			break;
		ft_dream(philo);
		if (ft_is_dead_flag(philo))
			break;
		ft_think(philo);
	}
	return (ptr);
}

/*
	Creates the threads for the philosophers and the observer.
	Join them all to the program thread.
	@param program: the program structure
	@param forks: the forks mutexes
	@return: 0 on success, -1 on failure
*/
int	ft_create_threads(t_prog *program, pthread_mutex_t *forks)
{
	pthread_t	observer;
	size_t		i;

	i = 0;
	if (pthread_create(&observer, NULL, &monitor_philos, program->philos) != 0)
		ft_destroy_all(program, forks, ERR_CREATE_THREAD);
	while (i < program->philos[0].nb_philo)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &start_routine,
				&program->philos[i]) != 0)
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
