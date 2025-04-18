/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:39:20 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/17 11:42:12 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

void	print_message(t_philo *philo, char *msg)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = ft_get_time() - philo->start_time;
	if (!ft_is_dead_flag(philo))
		printf("%zu %i %s\n", time, philo->id, msg);
	pthread_mutex_unlock(philo->write_lock);
}
