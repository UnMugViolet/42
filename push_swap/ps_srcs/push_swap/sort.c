/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:08:15 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/21 15:15:50 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_sclist **stack_a, t_sclist **stack_b)
{
	if (ft_issorted(*stack_a))
		return ;
	if (ft_sclst_size(*stack_a) <= 3)
	{
		ft_sort_three(stack_a);
		return ;
	}
	else
		ft_sort_big(stack_a, stack_b);
	if (ft_issorted(*stack_a))
		ft_printf("OK\n");
	else
	{
		ft_printf("KO\n");
		ft_sclst_print(stack_a, 'A');
	}
}
