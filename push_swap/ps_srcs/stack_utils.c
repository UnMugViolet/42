/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:31:56 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/08 10:54:46 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack **stack)
{
	t_stack	*begin;

	begin = *stack;
	while ((*stack)->next != begin)
	{
		ft_printf("Stack value: %i\naddress: %p\n", (*stack)->value, (*stack));
		*stack = (*stack)->next;
	}
	ft_printf("Stack value: %i\naddress: %p\n", (*stack)->value,
		(*stack)->next);
	ft_clean_stack(stack);
}

void	ft_clean_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*begin;

	begin = *stack;
	while ((*stack)->next != begin)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	free(*stack);
	free(stack);
}
