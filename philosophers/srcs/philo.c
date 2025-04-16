/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:14:38 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/16 20:00:55 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_prog			program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (!ft_is_valid_args(ac, av))
		return (1);
	ft_init_program(&program, philos);
	ft_init_forks(forks, ft_atoi(av[1]));
	return (0);
}
