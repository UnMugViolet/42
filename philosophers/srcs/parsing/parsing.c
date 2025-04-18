/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:10:51 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/18 10:00:24 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

bool	ft_check_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

bool	ft_is_valid_args(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (print_usage(), 0);
	if (ft_atoi(av[1]) > PHILO_MAX || ft_atoi(av[1]) <= 0)
		return (ft_putstr_fd(ERR_NB_PHILO, ERR_OUT), 0);
	if (ft_atoi(av[2]) <= 0 || !ft_check_isdigit(av[2]))
		return (ft_putstr_fd(ERR_NB_TIME, ERR_OUT), 0);
	if (ft_atoi(av[3]) <= 0 || !ft_check_isdigit(av[3]))
		return (ft_putstr_fd(ERR_NB_EAT, ERR_OUT), 0);
	if (ft_atoi(av[4]) <= 0 || !ft_check_isdigit(av[4]))
		return (ft_putstr_fd(ERR_NB_SLEEP, ERR_OUT), 0);
	if (ac == 6 && (ft_atoi(av[5]) <= 0 || !ft_check_isdigit(av[5])))
		return (ft_putstr_fd(ERR_NB_MEALS, ERR_OUT), 0);
	return (1);
}
