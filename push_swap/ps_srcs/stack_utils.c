/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:31:56 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/15 12:14:30 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_rotation_motion(t_sclist *a, t_sclist *b, int val)
{
	int	i;
	int	index_a;
	int	index_b;
	int	size_a;
	int	size_b;

	i = 0;
	size_a = ft_sclst_size(a);
	size_b = ft_sclst_size(b);
	index_a = ft_sclst_find_index(a, val);
	index_b = ft_sclst_find_index(b, val);
	if (index_a)
		i = size_a - index_a;
	if (index_b && (i < size_b - index_b))
		i = size_b - index_b;
	return (i);
}

bool	ft_issorted_from_min(t_sclist *stack_a)
{
	t_sclist	*temp;
	t_sclist	*begin;

	begin = ft_sclst_find_address((stack_a), ft_sclst_min(stack_a));
	temp = begin;
	while (temp->next != begin)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

bool	ft_issorted(t_sclist *stack_a)
{
	t_sclist	*begin;

	begin = stack_a;
	while (stack_a->next != begin)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

