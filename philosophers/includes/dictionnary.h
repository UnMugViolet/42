/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionnary.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:06:41 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/17 18:14:17 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONNARY_H
# define DICTIONNARY_H

# define ERR_OUT STDERR_FILENO
# define PHILO_MAX 200

# define RED "\033[31m"
# define RESET "\033[0m"
# define BOLD "\033[1m"


# define ERR_ARGS "Error: Invalid arguments\n"
# define ERR_MALLOC "Error: Malloc failed\n"
# define ERR_USAGE "Usage: ./philo [nb_of_philosophers] [time_to_die] \
[time_to_eat] [time_to_sleep] \
(option: [nb_of_times_each_philosopher_must_eat])\n"
# define ERR_NB_PHILO "Error: Invalid number of philosophers\n"
# define ERR_NB_EAT "Error: Invalid number time to eat\n"
# define ERR_NB_SLEEP "Error: Invalid number time to sleep\n"
# define ERR_NB_TIME "Error: Invalid time before dying value\n"
# define ERR_NB_MEALS "Error: Invalid number of meals\n"
# define ERR_CREATE_THREAD "Error: Failed to create thread\n"
# define ERR_JOIN_THREAD "Error: Failed to join threads\n"

#endif
