/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:38:11 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/22 10:08:11 by pjaguin          ###   ########.fr       */
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

void ft_get_forks(t_philo *philo, pthread_mutex_t **forks)
{
    if (!philo->l_fork || !philo->r_fork)
        return ;
    forks[0] = philo->r_fork;
    forks[1] = philo->l_fork;
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
    pthread_mutex_t    *forks[2];
    
    ft_get_forks(philo, forks);
    pthread_mutex_lock(forks[0]);
    print_message(philo, "has taken a fork");
    if (philo->nb_philo == 1)
    {
        ft_tiny_usleep(philo, philo->time_to_die);
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
    ft_tiny_usleep(philo, philo->time_to_eat);
    philo->is_eating = false;
    pthread_mutex_unlock(forks[1]);
    pthread_mutex_unlock(forks[0]);
}
