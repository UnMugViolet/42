/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_find.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:58:56 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/23 12:23:26 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sclst_find_index(t_sclist *stack, int value)
{
	int			index;
	t_sclist	*temp;

	index = 0;
	temp = stack;
	while (stack->next != temp)
	{
		if (stack->value == value)
			return (index);
		stack = stack->next;
		index++;
	}
	if (stack->value == value)
		return (index);
	return (-1);
}

t_sclist	*ft_sclst_find_address(t_sclist *stack, int value)
{
	t_sclist	*temp;

	temp = stack;
	while (stack->next != temp)
	{
		if (stack->value == value)
			return (stack);
		stack = stack->next;
	}
	if (stack->value == value)
		return (stack);
	return (NULL);
}

int	ft_find_value_place_a(t_sclist *stack_a, int to_push)
{
	int			i;
	t_sclist	*temp;

	i = 1;
	if (to_push < stack_a->value && to_push > ft_sclstlast(stack_a)->value)
		i = 0;
	else if (to_push > ft_sclst_max(stack_a) || to_push < ft_sclst_min(stack_a))
		i = ft_sclst_find_index(stack_a, ft_sclst_min(stack_a));
	else
	{
		temp = stack_a->next;
		while (to_push < stack_a->value || to_push > temp->value)
		{
			stack_a = stack_a->next;
			temp = stack_a->next;
			i++;
		}
	}
	return (i);
}

int	ft_find_value_place_b(t_sclist *stack_b, int to_push)
{
	int			i;
	t_sclist	*temp;

	i = 1;
	if (to_push > stack_b->value && to_push < ft_sclstlast(stack_b)->value)
		i = 0;
	else if (to_push > ft_sclst_max(stack_b) || to_push < ft_sclst_min(stack_b))
		i = ft_sclst_find_index(stack_b, ft_sclst_max(stack_b));
	else
	{
		temp = stack_b->next;
		while (to_push > stack_b->value || to_push < temp->value)
		{
			stack_b = stack_b->next;
			temp = stack_b->next;
			i++;
		}
	}
	return (i);
}
