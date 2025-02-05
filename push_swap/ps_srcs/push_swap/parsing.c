/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:06:28 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/05 10:54:15 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sclist	*ft_sclist_new(int content)
{
	t_sclist	*new_element;

	new_element = (t_sclist *)ft_calloc(sizeof(t_sclist), 1);
	if (!new_element)
		return (NULL);
	new_element->value = content;
	new_element->next = new_element;
	return (new_element);
}

t_sclist	*ft_sclstlast(t_sclist *stack)
{
	t_sclist	*begin;

	begin = stack;
	if (!stack)
		return (NULL);
	while (stack->next != begin)
		stack = stack->next;
	return (stack);
}

void	ft_sclist_addback(t_sclist **stack, t_sclist *new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = new;
	else
	{
		if (ft_sclstlast(*stack))
		{
			ft_sclstlast(*stack)->next = new;
			if (new)
				new->next = *stack;
		}
	}
}

t_sclist	**ft_parse(char **av, int ac)
{
	int			i;
	t_sclist	**stack_a;
	t_sclist	*curr_stack;

	i = 0;
	stack_a = (t_sclist **)ft_calloc(sizeof(t_sclist *), 1);
	if (!stack_a)
		return (NULL);
	while (++i < ac)
	{
		curr_stack = ft_sclist_new(ft_atoi(av[i]));
		if (!curr_stack)
			return (ft_sclst_clean(stack_a), NULL);
		ft_sclist_addback(stack_a, curr_stack);
	}
	return (stack_a);
}
