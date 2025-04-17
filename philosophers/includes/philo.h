/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:14:36 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/17 18:45:51 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	bool			is_eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	size_t			nb_philo;
	int				nb_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_prog
{
	int				dead_flag;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	t_philo			*philos;
}					t_prog;

# include "dictionnary.h"
# include "utils.h"

/* ----------------------------------INIT---------------------------------- */

void	ft_init_program(t_prog *program, t_philo *philos);
void	ft_init_forks(pthread_mutex_t *forks, int philo_count);
void	ft_init_philos(t_philo *philos, t_prog *program, pthread_mutex_t *forks,
			char **av);

/* ----------------------------------THREADS------------------------------- */

int		ft_create_threads(t_prog *program, pthread_mutex_t *forks);
bool	ft_is_philo_dead(t_philo *philo);
bool	ft_is_any_philo_dead(t_philo *philo);

/* ----------------------------------ACTIONS------------------------------- */

void	ft_eat(t_philo *philo);
void	ft_dream(t_philo *philo);
void	ft_think(t_philo *philo);

/* ----------------------------------MONITOR------------------------------- */

void	*monitor_philos(void *ptr);


#endif
