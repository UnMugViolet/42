/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:51:25 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/18 17:58:56 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

static void	ft_init_inputs(t_philo *philo, char **av)
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

/*
	Initialize the philosophers structure, it will create a philosopher
	structure for each philosopher. With default values for the
	attributes, and the forks mutexes.
	@param philos: the philosophers structure
	@param program: the program structure
	@param forks: the forks mutexes
	@param av: the arguments passed to the program
	@return: void
*/
void	ft_init_philos(t_philo *philo, t_prog *program, pthread_mutex_t *forks,
		char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philo[i].id = i + 1;
		philo[i].is_eating = false;
		philo[i].meals_eaten = 0;
		ft_init_inputs(&philo[i], av);
		philo[i].start_time = ft_get_time();
		philo[i].last_meal = ft_get_time();
		philo[i].write_lock = &program->write_lock;
		philo[i].dead_lock = &program->dead_lock;
		philo[i].meal_lock = &program->meal_lock;
		philo[i].dead = &program->simu_off;
		philo[i].l_fork = &forks[i];
		if (i == 0)
			philo[i].r_fork = &forks[philo[i].nb_philo - 1];
		else
			philo[i].r_fork = &forks[i - 1];
		i++;
	}
}

/*
	Initialize the forks mutexes, it will create a mutex for each fork
	(there is one fork per philosopher).
	We use a mutex to protect the access to the fork, so that only one
	philosopher can use it at a time.
	@param forks: the array of mutexes
	@param philo_count: the number of philosophers
	@return: void
*/
void	ft_init_forks(pthread_mutex_t *forks, int philo_count)
{
	int	i;

	i = 0;
	while (i < philo_count)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

/*
	Initialize the program structure, it will create the mutexes
	for the write, dead and meal locks.
	@param program: the program structure
	@param philos: the philosophers structure
	@return: void
*/
void	ft_init_program(t_prog *program, t_philo *philos)
{
	program->simu_off = 0;
	program->philos = philos;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}
