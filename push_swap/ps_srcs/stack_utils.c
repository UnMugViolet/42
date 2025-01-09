/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:31:56 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/09 17:45:49 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_issorted(t_stack *stack_a)
{
	t_stack	*begin;

	begin = stack_a;
	while (stack_a->next != begin)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

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

t_stackinfo	ft_init_stackinfo(t_stack *stack_a, t_stack *stack_b)
{
	t_stackinfo	info;

	info.total_size = ft_stacksize(stack_a) + ft_stacksize(stack_b);
	info.actual_size = info.total_size;
	info.min_b = 0;
	info.max_b = 0;
	return (info);
}
