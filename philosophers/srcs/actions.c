/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:38:11 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/18 10:12:51 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

void	ft_think(t_philo *philo)
{
	print_message(philo, "is thinking");
}

void	ft_dream(t_philo *philo)
{
	print_message(philo, "is dreaming");
	ft_usleep(philo->time_to_sleep);
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
	philo->last_meal = ft_get_time();
	print_message(philo, "is eating");
	ft_usleep(philo->time_to_eat);
	philo->is_eating = false;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
