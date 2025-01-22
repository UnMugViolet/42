/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_counter_ba.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:51:22 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/15 10:51:07 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_case_rarb_ba(t_sclist *a, t_sclist *b, int val)
{
	int	i;

	i = ft_find_value_place_a(a, val);
	if (i < ft_sclst_find_index(b, val))
		i = ft_sclst_find_index(b, val);
	return (i);
}

int	ft_case_rrarrb_ba(t_sclist *a, t_sclist *b, int val)
{
	int	i;

	i = 0;
	if (ft_find_value_place_a(a, val))
		i = ft_sclst_size(a) - ft_find_value_place_a(a, val);
	if (ft_sclst_find_index(b, val) && (i < (ft_sclst_size(b)
				- ft_sclst_find_index(b, val))))
		i = ft_sclst_size(b) - ft_sclst_find_index(b, val);
	return (i);
}

int	ft_case_rarrb_ba(t_sclist *a, t_sclist *b, int val)
{
	int	i;

	i = 0;
	if (ft_sclst_find_index(b, val))
		i = ft_sclst_size(b) - ft_find_value_place_a(b, val);
	i += ft_find_value_place_a(a, val);
	return (i);
}

int	ft_case_rrarb_ba(t_sclist *a, t_sclist *b, int val)
{
	int	i;

	i = 0;
	if (ft_find_value_place_a(a, val))
		i = ft_sclst_size(a) - ft_find_value_place_a(a, val);
	i += ft_sclst_find_index(b, val);
	return (i);
}
