/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:06:28 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/07 16:04:03 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int content)
{
	t_stack	*new_element;

	new_element = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if (!new_element)
		return (NULL);
	new_element->value = content;
	new_element->next = new_element;
	return (new_element);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*begin;

	begin = stack;
	if (!stack)
		return (NULL);
	while (stack->next != begin)
		stack = stack->next;
	return (stack);
}

void	ft_stack_addback(t_stack **stack, t_stack *new)
{
	if (!new || !stack)
		return ;
	if (!*stack)
		*stack = new;
	else
	{
		if (ft_stacklast(*stack))
			ft_stacklast(*stack)->next = new;
	}
}
