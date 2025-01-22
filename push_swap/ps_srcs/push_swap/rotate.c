/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:40:38 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/22 13:50:19 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_sclist **stack)
{
	*stack = (*stack)->next;
}

void	ra(t_sclist **stack_a, int is_quiet)
{
	if (stack_a && (*stack_a))
	{
		rotate(stack_a);
		if (!is_quiet)
			ft_putstr_fd("ra\n", 1);
	}
}

void	rb(t_sclist **stack_b, int is_quiet)
{
	if (stack_b && (*stack_b))
	{
		rotate(stack_b);
		if (!is_quiet)
			ft_putstr_fd("rb\n", 1);
	}
}

void	rr(t_sclist **stack_a, t_sclist **stack_b, int is_quiet)
{
	if ((stack_a && (*stack_a)) || (stack_b && (*stack_b)))
		if (!is_quiet)
			ft_putstr_fd("rr\n", 1);
	if (stack_a && (*stack_a))
		rotate(stack_a);
	if (stack_b && (*stack_b))
		rotate(stack_b);
}
