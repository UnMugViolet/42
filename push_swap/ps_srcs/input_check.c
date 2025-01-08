/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:09:35 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/07 15:12:57 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_overflowing(char *str)
{
	if (ft_atoi(str) == 0 && (ft_strncmp(str, "-0", 3) && ft_strncmp(str, "0",
				2)))
		return (1);
	return (0);
}

static bool	is_all_unique(char **av, int ac)
{
	int	*array;
	int	i;
	int	j;

	i = 0;
	array = (int *)ft_calloc(sizeof(int), (ac - 1));
	if (!array)
		return (free(array), 0);
	while (++i < ac)
	{
		if (is_overflowing(av[i]))
			return (free(array), 0);
		array[i - 1] = ft_atoi(av[i]);
	}
	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (++j < ac - 1)
			if (array[i] == array[j])
				return (free(array), 0);
		i++;
	}
	return (free(array), 1);
}

static bool	is_all_digits(char **av, int ac)
{
	int		start;
	size_t	i;

	start = 1;
	while (start < ac)
	{
		i = 0;
		while (av[start][i])
		{
			if (!ft_isdigit(av[start][i]) && !ft_is_whitespace((av[start][i]))
				&& !is_allowed_sign(av[start][i]))
				return (0);
			if (is_allowed_sign(av[start][i]) && !ft_isdigit(av[start][i + 1]))
				return (0);
			i++;
		}
		start++;
	}
	return (1);
}

bool	is_correct_input(char **av, int ac)
{
	if (ac < 2)
		return (ft_putstr_fd("Error\n", 2), 0);
	if (!is_all_digits(av, ac))
		return (ft_putstr_fd("Error\n", 2), 0);
	else if (!is_all_unique(av, ac))
		return (ft_putstr_fd("Error\n", 2), 0);
	else
		return (1);
}
