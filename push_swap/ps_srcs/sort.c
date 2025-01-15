/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:08:15 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/15 12:15:01 by pjaguin          ###   ########.fr       */
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
}
