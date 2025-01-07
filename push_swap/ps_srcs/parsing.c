/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:06:28 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/07 17:45:46 by pjaguin          ###   ########.fr       */
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
	if (!stack)
		return ;
	if (!*stack)
		*stack = new;
	else
	{
		if (ft_stacklast(*stack))
		{
			ft_stacklast(*stack)->next = new;
			if (new)
				new->next = *stack;
		}
	}
}

t_stack	**ft_parse(char **av, int ac)
{
	int		i;
	t_stack **stack_a;
	t_stack *curr_stack;

	i = 0;
	stack_a = (t_stack**)ft_calloc(sizeof(t_stack *), 1);
	if (!stack_a)
		return (free(stack_a), NULL);
	while (++i < ac)
	{
		curr_stack =  ft_stack_new(ft_atoi(av[i]));
		if (!curr_stack)
			return (ft_clean_stack(stack_a), NULL);
		ft_stack_addback(stack_a, curr_stack);
	}
	return (stack_a);
}
