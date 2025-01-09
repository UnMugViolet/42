/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:08:15 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/09 15:05:46 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_rasa(int first_val, int second_val, int last_val)
{
	return (first_val > last_val && first_val > second_val
		&& second_val > last_val);
}

static bool	is_sara(int first_val, int second_val, int last_val)
{
	return (first_val < second_val && first_val < last_val
		&& second_val > last_val);
}

static void	ft_sort_three(t_stack **stack_a, t_stackinfo info)
{
	int	first_val;
	int	second_val;
	int	last_val;

	first_val = (*stack_a)->value;
	second_val = (*stack_a)->next->value;
	last_val = ft_stacklast(*stack_a)->value;
	if (info.total_size == 2)
		return (ra(stack_a));
	if (is_rasa(first_val, second_val, last_val))
		return (ra(stack_a), sa(stack_a));
	if (is_sara(first_val, second_val, last_val))
		return (sa(stack_a), ra(stack_a));
	if (first_val > second_val && second_val < last_val && first_val < last_val)
		return (sa(stack_a));
	if (first_val > second_val && last_val > second_val && first_val > last_val)
		return (ra(stack_a));
	else
		rra(stack_a);
}

static void	ft_sort_big(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_a;
	(void)stack_b;
	ft_printf("Sort BIG been triggered\n\n");
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stackinfo	info;

	info = ft_init_stackinfo(*stack_a);
	if (ft_issorted(*stack_a))
		return ;
	if (info.total_size <= 3)
	{
		ft_sort_three(stack_a, info);
		return ;
	}
	else
		ft_sort_big(stack_a, stack_b);
}
