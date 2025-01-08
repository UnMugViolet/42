/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:17:50 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/08 17:25:53 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_push_swap(char **av, int ac)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = ft_parse(av, ac);
	if (!stack_a)
		return (0);
	stack_b = (t_stack **)ft_calloc(sizeof(t_stack *), 1);
	if (!stack_b)
		return (ft_clean_stack(stack_a), 0);
	return (ft_print_stack(stack_b) , pb(stack_a, stack_b),ft_print_stack(stack_a), 1);
}

int	main(int ac, char **av)
{
	if (!is_correct_input(av, ac))
		return (-1);
	if (!ft_push_swap(av, ac))
		return (-1);
	return (0);
}
