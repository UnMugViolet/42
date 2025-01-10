/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:53:34 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/10 16:58:30 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_sclist **stack_a, t_sclistinfo info)
{
	int	first_val;
	int	second_val;
	int	last_val;

	if (ft_issorted(*stack_a))
		return ;
	first_val = (*stack_a)->value;
	second_val = (*stack_a)->next->value;
	last_val = ft_sclstlast(*stack_a)->value;
	if (info.total_size == 2)
		return (ra(stack_a));
	if (first_val > last_val && first_val > second_val && second_val > last_val)
		return (ra(stack_a), sa(stack_a));
	if (first_val < second_val && first_val < last_val && second_val > last_val)
		return (sa(stack_a), ra(stack_a));
	if (first_val > second_val && second_val < last_val && first_val < last_val)
		return (sa(stack_a));
	if (first_val > second_val && last_val > second_val && first_val > last_val)
		return (ra(stack_a));
	else
		rra(stack_a);
}
