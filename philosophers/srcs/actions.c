/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:38:11 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/18 16:44:58 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

/*
	Sleeps for a given time in milliseconds. Perform a separations of sleeps
	and checks if something occurs in between.
	@param philo: the philosopher structure
	@param time: the time to sleep in milliseconds
*/
void	ft_do_micro_action(t_philo *philo, size_t time)
{
	size_t	segmented_sleep;

	segmented_sleep = time / 50;
	while (time > 0)
	{
		if (ft_is_dead_flag(philo))
			break ;
		if (time > segmented_sleep)
			ft_usleep(segmented_sleep);
		else
			ft_usleep(time);
		time -= segmented_sleep;
	}
}

/*
	Get the order of the forks for the philosopher in order to avoid deadlocks.
	@param philo: the philosopher structure
	@param forks: the forks mutexes
	@return: void
*/
void	ft_get_forks_order(t_philo *philo, pthread_mutex_t **forks)
{
	if (!philo->r_fork || !philo->l_fork)
		return ;
	if (philo->r_fork < philo->l_fork)
    {
        forks[0] = philo->r_fork;
        forks[1] = philo->l_fork;
    }
    else
    {
        forks[0] = philo->l_fork;
        forks[1] = philo->r_fork;
    }
}

void	ft_think(t_philo *philo)
{
	print_message(philo, "is thinking");
}

void	ft_dream(t_philo *philo)
{
	print_message(philo, "is sleeping");
	ft_do_micro_action(philo, philo->time_to_sleep);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_t *forks[2];
	
	ft_get_forks_order(philo, forks);
	pthread_mutex_lock(forks[0]);
	print_message(philo, "has taken a fork");
	if (philo->nb_philo == 1)
	{
		ft_do_micro_action(philo, philo->time_to_die);
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
	ft_do_micro_action(philo, philo->time_to_eat);
	philo->is_eating = false;
	pthread_mutex_unlock(forks[1]);
	pthread_mutex_unlock(forks[0]);
}
