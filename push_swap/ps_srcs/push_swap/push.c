/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:31:44 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/05 11:03:40 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_sclist **stack_from, t_sclist **stack_to)
{
	t_sclist	*temp;

	temp = *stack_from;
	if ((*stack_from)->next != *stack_from)
	{
		ft_sclst_last(*stack_from)->next = (*stack_from)->next;
		*stack_from = (*stack_from)->next;
	}
	else
		*stack_from = NULL;
	if (!(*stack_to))
		*stack_to = temp;
	temp->next = (*stack_to);
	ft_sclst_last(*stack_to)->next = temp;
	*stack_to = temp;
}

void	pb(t_sclist **stack_a, t_sclist **stack_b, int is_quiet)
{
	if (!(*stack_a) || !stack_a)
		return ;
	push(stack_a, stack_b);
	if (!is_quiet)
		ft_putstr_fd("pb\n", 1);
}

void	pa(t_sclist **stack_a, t_sclist **stack_b, int is_quiet)
{
	if (!(*stack_b) || !stack_b)
		return ;
	push(stack_b, stack_a);
	if (!is_quiet)
		ft_putstr_fd("pa\n", 1);
}
