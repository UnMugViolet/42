/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:08:15 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/09 17:47:19 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stackinfo	info;

	info = ft_init_stackinfo(*stack_a, *stack_b);
	if (ft_issorted(*stack_a))
		return ;
	if (info.total_size <= 3)
	{
		ft_sort_three(stack_a, info);
		return ;
	}
	else
		ft_sort_big(stack_a, stack_b, info);
}
