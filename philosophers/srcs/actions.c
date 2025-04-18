/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:38:11 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/18 19:49:09 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

// TODO add the function to do tiny usleeps instead of one large

/*
	Get the order of the forks for the philosopher in order to avoid deadlocks.
	@param philo: the philosopher structure
	@param forks: the forks mutexes
	@return: void
*/
void	ft_get_forks_order(t_philo *philo, pthread_mutex_t **forks)
{
	if (!philo->r_fork || !philo->l_fork)
    	return;
	if (philo->id % 2 == 1)
	{
		forks[0] = philo->l_fork;
		forks[1] = philo->r_fork;
	}
	else
	{
		forks[0] = philo->r_fork;
		forks[1] = philo->l_fork;
	}
}

void	ft_think(t_philo *philo)
{
	print_message(philo, "is thinking");
}

void	ft_dream(t_philo *philo)
{
	print_message(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_t *forks[2];
	
	ft_get_forks_order(philo, forks);
	pthread_mutex_lock(forks[0]);
	print_message(philo, "has taken a fork");
	if (philo->nb_philo == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(forks[0]);
		return ;
	}
	pthread_mutex_lock(forks[1]);
	print_message(philo, "has taken a fork");
	philo->is_eating = true;
	print_message(philo, "is eating");
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = ft_get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->is_eating = false;
	pthread_mutex_unlock(forks[1]);
	pthread_mutex_unlock(forks[0]);
}
