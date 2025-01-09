/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:53:07 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/09 11:06:32 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	*stack = ft_stacklast(*stack);
}

void	rra(t_stack **stack_a)
{
	if (stack_a && (*stack_a))
	{
		reverse_rotate(stack_a);
		ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_stack **stack_b)
{
	if (stack_b && (*stack_b))
	{
		reverse_rotate(stack_b);
		ft_putstr_fd("rrb\n", 1);
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((stack_a && *stack_a) || (stack_b && *stack_b))
		ft_putstr_fd("rrr\n", 1);
	if (stack_a && *stack_a)
		reverse_rotate(stack_a);
	if (stack_b && *stack_b)
		reverse_rotate(stack_b);
}
