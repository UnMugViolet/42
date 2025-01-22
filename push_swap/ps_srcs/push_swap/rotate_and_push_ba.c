/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push_ba.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:49:40 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/22 13:53:23 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_apply_rarb_ba(t_sclist **a, t_sclist **b, int value)
{
	while ((*b)->value != value && ft_find_value_place_a(*a, value) > 0)
		rr(a, b, 0);
	while ((*b)->value != value)
		rb(b, 0);
	while (ft_find_value_place_a(*a, value) > 0)
		ra(a, 0);
	pa(a, b, 0);
	return (-1);
}

int	ft_apply_rrarrb_ba(t_sclist **a, t_sclist **b, int value)
{
	while ((*b)->value != value && ft_find_value_place_a(*a, value) > 0)
		rrr(a, b, 0);
	while ((*b)->value != value)
		rrb(b, 0);
	while (ft_find_value_place_a(*a, value) > 0)
		rra(a, 0);
	pa(a, b, 0);
	return (-1);
}

int	ft_apply_rrarb_ba(t_sclist **a, t_sclist **b, int value)
{
	while ((*b)->value != value)
		rb(b, 0);
	while (ft_find_value_place_a(*a, value) > 0)
		rra(a, 0);
	pa(a, b, 0);
	return (-1);
}

int	ft_apply_rarrb_ba(t_sclist **a, t_sclist **b, int value)
{
	while (ft_find_value_place_a(*a, value) > 0)
		ra(a, 0);
	while ((*b)->value != value)
		rrb(b, 0);
	pa(a, b, 0);
	return (-1);
}
