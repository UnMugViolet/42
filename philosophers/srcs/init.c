/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:51:25 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/16 20:37:01 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void ft_init_inputs(t_philo *philo, char **av)
{
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->nb_philo = ft_atoi(av[1]);
	if (av[5])
		philo->nb_times_to_eat = ft_atoi(av[5]);
	else
		philo->nb_times_to_eat = -1;
}

void	ft_init_philos(t_philo *philo, t_prog *prog, pthread_mutex_t *forks, char **av)
{
	int	i;

	i = -1;
	while (i++ < ft_atoi(av[1]))
	{
		philo[i].id = i + 1;
		philo[i].is_eating = false;
		philo[i].meals_eaten = 0;
		ft_init_inputs(&philo[i], av);
		philo[i].start_time = ft_get_time();
		philo[i].last_meal = ft_get_time();
		philo[i].write_lock = &prog->write_lock;
		philo[i].dead_lock = &prog->dead_lock;
		philo[i].meal_lock = &prog->meal_lock;
		philo[i].dead = &prog->dead_flag;
		philo[i].l_fork = &forks[i];
		if (i == 0)
			philo[i].r_fork = &forks[philo[i].nb_philo - 1];
		else
			philo[i].r_fork = &forks[i - 1];
	}
}

void	ft_init_forks(pthread_mutex_t *forks, int philo_count)
{
	int	i;

	i = -1;
	while (i++ < philo_count)
		pthread_mutex_init(&forks[i], NULL);
}

void	ft_init_program(t_prog *prog, t_philo *philos)
{
	prog->dead_flag = 0;
	prog->philos = philos;
	pthread_mutex_init(&prog->write_lock, NULL);
	pthread_mutex_init(&prog->dead_lock, NULL);
	pthread_mutex_init(&prog->meal_lock, NULL);
}
