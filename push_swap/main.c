/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:17:50 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/14 15:30:10 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_push_swap(char **av, int ac)
{
	t_sclist	**stack_a;
	t_sclist	**stack_b;

	stack_a = ft_parse(av, ac);
	ft_printf("SIZE: %i\n", ft_sclst_size((*stack_a)));
	if (!stack_a)
		return (0);
	stack_b = (t_sclist **)ft_calloc(sizeof(t_sclist *), 1);
	if (!stack_b)
		return (ft_sclst_clean(stack_a), 0);
	return (sort(stack_a, stack_b), ft_sclst_clean(stack_a), free(stack_b), 1);
}

int	main(int ac, char **av)
{
	if (!is_correct_input(av, ac))
		return (-1);
	if (!ft_push_swap(av, ac))
		return (-1);
	return (0);
}
