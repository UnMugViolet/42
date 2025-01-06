/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:09:35 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/06 14:26:16 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps_includes/push_swap.h"

bool	is_all_unique(char **av, int ac)
{
	(void)ac;
	(void)av;
	return (1);
}

bool	is_all_digits(char **av, int ac)
{
	int	start;
	int	i;

	start = 1;
	i = 0;
	while (start < ac - 1)
	{
		while (av[start][i])
		{
			if (!ft_isdigit(av[start][i]) || !ft_is_whitespace((av[start][i])))
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
		return (ft_putstr_fd("Error too few arguments\n", 2), 0);
	if (!is_all_digits(av, ac))
		return (ft_putstr_fd("Error some arguments are not digits\n", 2), 0);
	else if (!is_all_unique(av, ac))
		return (ft_putstr_fd("Error some numbers are duplicated\n", 2), 0);
	else
		return (1);
}
