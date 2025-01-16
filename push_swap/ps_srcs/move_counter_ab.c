/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_counter_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:51:22 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/16 17:02:54 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_case_rarb_ab(t_sclist *a, t_sclist *b, int val)
{
	int	i;

	i = ft_find_value_place_b(b, val);
	if (i < ft_sclst_find_index(a, val))
		i = ft_sclst_find_index(a, val);
	return (i);
}

int	ft_case_rrarrb_ab(t_sclist *a, t_sclist *b, int val)
{
	int	i;

	i = 0;
	if (ft_find_value_place_b(b, val))
		i = ft_sclst_size(b) - ft_find_value_place_b(b, val);
	if (ft_sclst_find_index(a, val) && (i < (ft_sclst_size(a)
				- ft_sclst_find_index(a, val))))
		i = ft_sclst_size(a) - ft_sclst_find_index(a, val);
	return (i);
}

int	ft_case_rrarb_ab(t_sclist *a, t_sclist *b, int val)
{
	int	i;

	i = 0;
	if (ft_sclst_find_index(a, val))
		i = ft_sclst_size(a) - ft_find_value_place_a(a, val);
	i += ft_find_value_place_b(b, val);
	return (i);
}

int	ft_case_rarrb_ab(t_sclist *a, t_sclist *b, int val)
{
	int	i;

	i = 0;
	if (ft_find_value_place_b(b, val))
		i = ft_sclst_size(b) - ft_find_value_place_b(b, val);
	i += ft_sclst_find_index(a, val);
	return (i);
}
