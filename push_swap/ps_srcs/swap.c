/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:56:36 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/10 16:58:30 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_sclist **stack)
{
	t_sclist	*temp_first;
	t_sclist	*temp_second;
	t_sclist	*temp_third;

	temp_first = *stack;
	temp_second = (*stack)->next;
	temp_third = (*stack)->next->next;
	if ((*stack)->next != *stack)
	{
		if (ft_sclst_size(*stack) == 2)
		{
			*stack = (*stack)->next;
			return ;
		}
		ft_sclstlast(*stack)->next = temp_second;
		temp_second->next = temp_first;
		temp_first->next = temp_third;
		(*stack) = temp_second;
	}
}

void	sa(t_sclist **stack_a)
{
	if (stack_a && *stack_a)
	{
		swap(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_sclist **stack_b)
{
	if (stack_b && *stack_b)
	{
		swap(stack_b);
		ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_sclist **stack_a, t_sclist **stack_b)
{
	if ((stack_a && *stack_a) || (stack_b && *stack_b))
		ft_putstr_fd("ss\n", 1);
	if (stack_a && *stack_a)
		swap(stack_a);
	if (stack_b && *stack_b)
		swap(stack_b);
}
