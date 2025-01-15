/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push_ba.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:49:40 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/15 12:18:19 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_apply_rarb_ba(t_sclist **a, t_sclist **b, int value)
{
	while ((*b)->value != value && ft_find_value_place_a(*a, value) > 0)
		rr(a, b);
	while ((*b)->value != value)
		rb(b);
	while (ft_find_value_place_a(*a, value) > 0)
		ra(a);
	pb(a, b);
	return (-1);
}

int	ft_apply_rrarrb_ba(t_sclist **a, t_sclist **b, int value)
{
	while ((*b)->value != value && ft_find_value_place_a(*a, value) > 0)
		rrr(a, b);
	while ((*b)->value != value)
		rrb(b);
	while (ft_find_value_place_a(*a, value) > 0)
		rra(a);
	pb(a, b);
	return (-1);
}

int	ft_apply_rrarb_ba(t_sclist **a, t_sclist **b, int value)
{
	while ((*b)->value != value)
		rra(a);
	while (ft_find_value_place_a(*a, value) > 0)
		rb(b);
	pb(a, b);
	return (-1);
}

int	ft_apply_rarrb_ba(t_sclist **a, t_sclist **b, int value)
{
	while (ft_find_value_place_a(*a, value) > 0)
		ra(a);
	while ((*b)->value != value)
		rrb(b);
	pb(a, b);
	return (-1);
}
