/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:06:44 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/10 17:54:19 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_is_between_two(t_sclist **stack_a, t_sclist **stack_b)
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
}

int	ft_init_pb(t_sclist **stack_a, t_sclist **stack_b, t_sclistinfo info)
{
	size_t		index;
	t_sclist	*temp;

	while (info.current_size_a > 3 && ft_sclst_size(*stack_b) < 2)
	{
		if (ft_issorted(ft_sclst_find_address(*stack_a, info.min)))
		{
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
					ft_sclst_print(stack_a, 'A');
					rra(stack_a);
				}
			}
			return (0);
		}
		pb(stack_a, stack_b);
		info.current_size_a--;
	}
	return (1);
}

void	ft_sort_big(t_sclist **stack_a, t_sclist **stack_b, t_sclistinfo info)
{
	ft_init_pb(stack_a, stack_b, info);
	ft_sclst_print(stack_a, 'A');
	ft_sclst_print(stack_b, 'B');
}
