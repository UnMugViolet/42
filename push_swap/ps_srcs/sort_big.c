/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:06:44 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/14 11:27:26 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static bool	ft_is_between_two(t_sclist **stack_a, t_sclist **stack_b)
{
	int	curr_a_val;
	int	curr_b_val;
	int	last_a_val;

	curr_a_val = (*stack_a)->value;
	curr_b_val = (*stack_b)->value;
	last_a_val = ft_sclstlast(*stack_a)->value;
	if (!(*stack_a) || !(*stack_b))
		return (0);
	return (curr_a_val < curr_b_val && last_a_val > curr_b_val);
} */

/* static size_t	ft_cheapest_index(t_sclist *stack_from, t_sclist *stack_to,
		t_sclistinfo info)
{
	t_sclist	*temp;
	size_t		counter;

	temp = stack_from;
	counter = 0;
	while (stack_from->next != temp)
	{
		if ()
		stack_from->value 
	}
	return (counter);
} */

/* static void	ft_push_in_between(t_sclist **stack_a, t_sclist **stack_b,
		t_sclistinfo info)
{
	int			index;
	t_sclist	*temp;

	temp = ft_sclst_find_address(*stack_a, info.min);
	index = ft_sclst_find_index(*stack_a, info.min);
	if (index <= ft_sclst_size(*stack_a) / 2)
	{
		while (*stack_a != temp)
		{
			if (ft_is_between_two(stack_a, stack_b))
				pa(stack_a, stack_b);
			ra(stack_a);
		}
	}
	else
	{
		while (*stack_a != temp)
		{
			if (ft_is_between_two(stack_a, stack_b))
				pa(stack_a, stack_b);
			rra(stack_a);
		}
	}
	return ;
} */

int	ft_sort_pb(t_sclist **stack_a, t_sclist **stack_b, t_sclistinfo info)
{
	if (ft_sclst_size(*stack_a) > 3 && !ft_issorted(ft_sclst_find_address((*stack_a), ft_sclst_min((*stack_a)))))
		pb(stack_a, stack_b);
	if (ft_sclst_size(*stack_a) > 3 && !ft_issorted(ft_sclst_find_address((*stack_a), ft_sclst_min((*stack_a)))))
		pb(stack_a, stack_b);
	ft_printf("Valeur de rotation : %i\n", ft_get_rotation_motion(*stack_a, *stack_b, (*stack_a)->next->value));
/* 	if (ft_lstsize(*stack_a) > 3 && !ft_issorted(ft_sclst_min(stack_a)))
		trierBetpb_au_bon_moment_jusqua3ouft_issorted(ft_sclst_min(stack_a))(stack_a, stack_b); */
	if (!ft_issorted((*stack_a)))
		ft_sort_three(stack_a, info);
	return (1);
}

/* t_sclist	*sort_b(t_sclist **stack_a, t_sclist **stack_b)
{
} */

void	ft_sort_big(t_sclist **stack_a, t_sclist **stack_b, t_sclistinfo info)
{
	ft_sclst_print(stack_a, 'A');
	ft_sclst_print(stack_b, 'B');
	ft_sort_pb(stack_a, stack_b, info);
	ft_sclst_print(stack_a, 'A');
	ft_sclst_print(stack_b, 'B');
}
