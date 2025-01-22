/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:53:34 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/22 13:52:07 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_sclist **stack_a)
{
	int	first_val;
	int	second_val;
	int	last_val;

	if (ft_issorted(*stack_a))
		return ;
	first_val = (*stack_a)->value;
	second_val = (*stack_a)->next->value;
	last_val = ft_sclstlast(*stack_a)->value;
	if (ft_sclst_size(*stack_a) == 2)
		return (ra(stack_a, 0));
	if (first_val > last_val && first_val > second_val && second_val > last_val)
		return (ra(stack_a, 0), sa(stack_a, 0));
	if (first_val < second_val && first_val < last_val && second_val > last_val)
		return (sa(stack_a, 0), ra(stack_a, 0));
	if (first_val > second_val && second_val < last_val && first_val < last_val)
		return (sa(stack_a, 0));
	if (first_val > second_val && last_val > second_val && first_val > last_val)
		return (ra(stack_a, 0));
	else
		rra(stack_a, 0);
}
