/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:06:44 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/15 12:24:00 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_push_sort_a(t_sclist **a, t_sclist **b)
{
	int			i;
	t_sclist	*temp;

	temp = *b;
	i = ft_get_cheapest_ba((*a), (*b));
	while (ft_sclst_size(*a) > 3 && !ft_issorted_from_min(*a))
	{
		while (i >= 0)
		{
			if (i == ft_case_rarb_ba(*a, *b, temp->value))
				i = ft_apply_rarb_ba(a, b, temp->value);
			else if (i == ft_case_rrarrb_ba(*a, *b, temp->value))
				i = ft_apply_rrarrb_ba(a, b, temp->value);
			else if (i == ft_case_rarrb_ba(*a, *b, temp->value))
				i = ft_apply_rarrb_ba(a, b, temp->value);
			else if (i == ft_case_rrarb_ba(*a, *b, temp->value))
				i = ft_apply_rrarb_ba(a, b, temp->value);
			else
				temp = temp->next;
		}
	}
}

void	push_into_b(t_sclist **a, t_sclist **b)
{
	int			i;
	t_sclist	*temp;

	temp = *a;
	i = ft_get_cheapest_ab((*a), (*b));
	while (ft_sclst_size(*a) > 3 && !ft_issorted_from_min(*a))
	{
		while (i >= 0)
		{
			if (i == ft_case_rarb_ab(*a, *b, temp->value))
				i = ft_apply_rarb_ab(a, b, temp->value);
			else if (i == ft_case_rrarrb_ab(*a, *b, temp->value))
				i = ft_apply_rrarrb_ab(a, b, temp->value);
			else if (i == ft_case_rarrb_ab(*a, *b, temp->value))
				i = ft_apply_rarrb_ab(a, b, temp->value);
			else if (i == ft_case_rrarb_ab(*a, *b, temp->value))
				i = ft_apply_rrarb_ab(a, b, temp->value);
			else
				temp = temp->next;
		}
	}
}

void	ft_init_b(t_sclist **stack_a, t_sclist **stack_b)
{
	if (ft_sclst_size(*stack_a) > 3 && !ft_issorted_from_min(*stack_a))
		pb(stack_a, stack_b);
	if (ft_sclst_size(*stack_a) > 3 && !ft_issorted_from_min(*stack_a))
		pb(stack_a, stack_b);
	if (ft_sclst_size(*stack_a) > 3 && !ft_issorted_from_min(*stack_a))
		push_into_b(stack_a, stack_b);
}

void	ft_sort_big(t_sclist **stack_a, t_sclist **stack_b)
{
	ft_init_b(stack_a, stack_b);
	if (!ft_issorted_from_min((*stack_a)))
		ft_sort_three(stack_a);
	ft_push_sort_a(stack_a, stack_b);
}
