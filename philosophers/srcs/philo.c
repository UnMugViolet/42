/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:14:38 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/18 17:24:19 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

int	main(int ac, char **av)
{
	t_prog			program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (!ft_is_valid_args(ac, av))
		return (1);
	ft_init_program(&program, philos);
	ft_init_forks(forks, ft_atoi(av[1]));
	ft_init_philos(philos, &program, forks, av);
	if (ft_create_threads(&program, forks) == -1)
		return (EXIT_FAILURE);
	ft_destroy_all(&program, forks, NULL);
	return (0);
}
