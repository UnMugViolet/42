/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:31:56 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/08 16:23:45 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_stacksize(t_stack *stack)
{
	t_stack	*begin;
	size_t	count;

	begin = stack;
	if (!stack)
		return (0);
	count = 1;
	while (stack->next != begin)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

void	ft_print_stack(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (!stack || !(*stack))
		return ;
	while (temp->next != (*stack))
	{
		ft_printf("Stack value: %i\naddress: %p\n", temp->value, temp);
		temp = temp->next;
	}
	ft_printf("Pointed by last: %i\naddress: %p\n", temp->value, temp->next);
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
