/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:31:56 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/10 11:11:27 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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


t_sclistinfo	ft_init_sclistinfo(t_sclist *stack_a, t_sclist *stack_b)
{
	t_sclistinfo	info;

	(void)stack_b;
	info.total_size = ft_sclst_size(stack_a);
	info.actual_size = info.total_size;
	info.min = 0;
	info.max = 0;
	return (info);
}
