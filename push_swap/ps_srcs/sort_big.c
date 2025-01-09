/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:06:44 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/09 17:50:44 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_big(t_stack **stack_a, t_stack **stack_b, t_stackinfo info)
{
	while (info.actual_size > 3 && ft_stacksize(*stack_b) < 2)
	{
		pb(stack_a, stack_b);
		info.actual_size--;
		if (ft_issorted(*stack_a))
		{
			
			return ;
		}
	}
	ft_print_stack(stack_a);
	ft_sort_three(stack_a, info);
	ft_print_stack(stack_a);
	ft_printf("\nStack B:\n");
	ft_print_stack(stack_b);
}
