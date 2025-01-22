/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push_ab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:49:40 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/15 13:49:46 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_apply_rarb_ab(t_sclist **a, t_sclist **b, int value)
{
	while ((*a)->value != value && ft_find_value_place_b(*b, value) > 0)
		rr(a, b);
	while ((*a)->value != value)
		ra(a);
	while (ft_find_value_place_b(*b, value) > 0)
		rb(b);
	pb(a, b);
	return (-1);
}

int	ft_apply_rrarrb_ab(t_sclist **a, t_sclist **b, int value)
{
	while ((*a)->value != value && ft_find_value_place_b(*b, value) > 0)
		rrr(a, b);
	while ((*a)->value != value)
		rra(a);
	while (ft_find_value_place_b(*b, value) > 0)
		rrb(b);
	pb(a, b);
	return (-1);
}

int	ft_apply_rrarb_ab(t_sclist **a, t_sclist **b, int value)
{
	while ((*a)->value != value)
		rra(a);
	while (ft_find_value_place_b(*b, value) > 0)
		rb(b);
	pb(a, b);
	return (-1);
}

int	ft_apply_rarrb_ab(t_sclist **a, t_sclist **b, int value)
{
	while ((*a)->value != value)
		ra(a);
	while (ft_find_value_place_b(*b, value) > 0)
		rrb(b);
	pb(a, b);
	return (-1);
}
