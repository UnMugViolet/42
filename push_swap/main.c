/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:17:50 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/09 11:20:49 by pjaguin          ###   ########.fr       */
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
	return (
		ft_printf("Origin:\n"),
		ft_print_stack(stack_a),
		sa(stack_a),
		ft_printf("\n\n\nStack B:\n"),
		ft_print_stack(stack_b),
		ft_printf("\n\n\nStack A:\n"),
		ft_print_stack(stack_a), 1
	);
}

int	main(int ac, char **av)
{
	if (!is_correct_input(av, ac))
		return (-1);
	if (!ft_push_swap(av, ac))
		return (-1);
	return (0);
}