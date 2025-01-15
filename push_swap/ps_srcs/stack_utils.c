/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:31:56 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/14 17:01:26 by pjaguin          ###   ########.fr       */
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

t_sclistinfo	ft_init_sclistinfo(t_sclist *stack_a)
{
	t_sclistinfo	info;

	if (!stack_a)
	{
		info.total_size = 0;
		info.current_size_a = 0;
		info.min = 0;
		info.max = 0;
		return (info);
	}
	info.total_size = ft_sclst_size(stack_a);
	info.current_size_a = info.total_size;
	if (!info.total_size)
	{
		info.min = 0;
		info.max = 0;
	}
	else
	{
		info.min = ft_sclst_min(stack_a);
		info.max = ft_sclst_max(stack_a);
	}
	return (info);
}
