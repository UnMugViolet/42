/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:31:44 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/09 11:17:23 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*temp;

	temp = *stack_from;
	if ((*stack_from)->next != *stack_from)
	{
		ft_stacklast(*stack_from)->next = (*stack_from)->next;
		*stack_from = (*stack_from)->next;
	}
	else
		*stack_from = NULL;
	if (!(*stack_to))
		*stack_to = temp;
	temp->next = (*stack_to);
	ft_stacklast(*stack_to)->next = temp;
	*stack_to = ft_stacklast(*stack_to)->next;
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a) || !stack_a)
		return ;
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_b) || !stack_b)
		return ;
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}