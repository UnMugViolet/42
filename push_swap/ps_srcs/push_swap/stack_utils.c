/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:31:56 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/21 16:01:48 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
