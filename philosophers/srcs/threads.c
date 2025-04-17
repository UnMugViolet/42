/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:16:42 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/17 12:10:36 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

/*
	That function will be called into a loop in the thread function.
	It will check if the philosopher is dead, and if so, it will
	print the message and return true.
	`mutex` are used to protect the access to the shared data.
	@param philo: the philosopher structure
	@return: true if the philosopher is dead, false otherwise
*/
bool	ft_is_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead)
		return (pthread_mutex_unlock(philo->dead_lock), true);
	pthread_mutex_unlock(philo->dead_lock);
	return (false);
}

int	ft_create_threads(t_prog *program, pthread_mutex_t *forks)
{
	(void)program;
	(void)forks;
	return (0);
}
