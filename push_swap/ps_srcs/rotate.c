/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:40:38 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/10 10:49:39 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_sclist **stack)
{
	*stack = (*stack)->next;
}

void	ra(t_sclist **stack_a)
{
	if (stack_a && (*stack_a))
	{
		rotate(stack_a);
		ft_putstr_fd("ra\n", 1);
	}
}

void	rb(t_sclist **stack_b)
{
	if (stack_b && (*stack_b))
	{
		rotate(stack_b);
		ft_putstr_fd("rb\n", 1);
	}
}

void	rr(t_sclist **stack_a, t_sclist **stack_b)
{
	if ((stack_a && (*stack_a)) || (stack_b && (*stack_b)))
		ft_putstr_fd("rr\n", 1);
	if (stack_a && (*stack_a))
		rotate(stack_a);
	if (stack_b && (*stack_b))
		rotate(stack_b);
}
