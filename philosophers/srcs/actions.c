/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:38:11 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/19 11:09:02 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

/*
	Performs mico actions to avoid waiting for all the time if a philosopher
	died. This function will split the time to sleep into 50 parts and sleep
	for each part. This way, if a philosopher dies, the program will not
	wait.
	@param philo: the philosopher structure
	@param time: the time to sleep
	@return: void
*/
void ft_tiny_usleep(t_philo *philo, size_t time)
{
    size_t chunk;
    chunk = 10;
    while (time > 0)
    {
        if (ft_is_dead_flag(philo))
            return;
        if (chunk > time)
            chunk = time;
        ft_usleep(chunk);
        time -= chunk;
    }
}

void	ft_think(t_philo *philo)
{
	print_message(philo, "is thinking");
}

void	ft_dream(t_philo *philo)
{
	print_message(philo, "is sleeping");
	ft_tiny_usleep(philo, philo->time_to_sleep);
}

void	ft_eat(t_philo *philo)
{
    pthread_mutex_lock(philo->r_fork);
    print_message(philo, "has taken a fork");
    if (philo->nb_philo == 1)
    {
        ft_usleep(philo->time_to_die);
        pthread_mutex_unlock(philo->r_fork);
        return ;
    }
    pthread_mutex_lock(philo->l_fork);
    print_message(philo, "has taken a fork");
    philo->is_eating = true;
    print_message(philo, "is eating");
    pthread_mutex_lock(philo->meal_lock);
    philo->last_meal = ft_get_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(philo->meal_lock);
    ft_usleep(philo->time_to_eat);
    philo->is_eating = false;
    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
}
