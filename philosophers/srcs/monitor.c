/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:40:06 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/17 19:07:36 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

/*
	Checks if the philosopher is dead by comparing the `current time`
	and the `last meal time` of the philosopher.
	@param philo: the philosopher structure
	@return: true if the philosopher is dead, false otherwise
*/
bool	ft_is_philo_dead(t_philo *philo)
{
	printf("%zu %zu %zu\n", ft_get_time(), philo->last_meal, philo->time_to_die);
	pthread_mutex_lock(philo->meal_lock);
	if (ft_get_time() - philo->last_meal >= philo->time_to_die && !philo->is_eating)
		return (pthread_mutex_unlock(philo->meal_lock), true);
	pthread_mutex_unlock(philo->meal_lock);
	return (false);
}

bool	ft_is_any_philo_dead(t_philo * philo)
{
	size_t	i;

	i = -1;
	while (i++ < philo[0].nb_philo)
	{
		if (ft_is_philo_dead(&philo[i]))
		{
			print_message(&philo[i], "died");
			pthread_mutex_lock(philo[0].dead_lock);
			*philo->dead = true;
			pthread_mutex_unlock(philo[0].dead_lock);
			return (true);
		}
	}
	return (false);
}

/*
	That function will check if all the philosophers have eaten
	the number of times specified in the arguments.
	If so, it will set the dead flag to true and return true.
	@param philo: the philosopher structure
	@return: true if all the philosophers have eaten, false otherwise
*/
bool	ft_all_philos_ate(t_philo *philo)
{
	size_t	i;
	size_t	count_philo_eaten;
	
	i = 0;
	count_philo_eaten = 0;
	if (philo[0].nb_times_to_eat == -1)
		return (false);
	while (i < philo[0].nb_philo)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].meals_eaten >= philo[0].nb_times_to_eat)
			count_philo_eaten++;
		else
			count_philo_eaten = 0;
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	if (count_philo_eaten == philo[0].nb_philo)
	{
		pthread_mutex_lock(philo[0].dead_lock);
		*philo->dead = true;
		pthread_mutex_unlock(philo[0].dead_lock);
		return (true);
	}
	return (false);
}

/*
	Used in the `pthread_create` function to create the thread
	It will call the `ft_is_any_philo_dead` function to check if the
	the philosopher is dead or if all the philosophers have eaten.
	If so, it will break the loop and return.
	@param ptr: the philosopher structure
	@return: the philosopher structure
*/
void	*monitor_philos(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (true)
		if (ft_is_any_philo_dead(philo) || ft_all_philos_ate(philo))
			break ;
	return (ptr);
}
