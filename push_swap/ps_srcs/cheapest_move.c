/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:58:47 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/21 18:19:37 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_cheapest_ba(t_sclist *a, t_sclist *b)
{
	int			cheapest;
	t_sclist	*temp;

	temp = b;
	cheapest = ft_case_rrarrb_ba(a, b, temp->value);
	do
	{
		if (cheapest > ft_case_rarb_ba(a, b, temp->value))
			cheapest = ft_case_rarb_ba(a, b, temp->value);
		if (cheapest > ft_case_rrarrb_ba(a, b, temp->value))
			cheapest = ft_case_rrarrb_ba(a, b, temp->value);
		if (cheapest > ft_case_rarrb_ba(a, b, temp->value))
			cheapest = ft_case_rarrb_ba(a, b, temp->value);
		if (cheapest > ft_case_rrarb_ba(a, b, temp->value))
			cheapest = ft_case_rrarb_ba(a, b, temp->value);
		temp = temp->next;
	} while (temp != b);
	return (cheapest);
}

int	ft_get_cheapest_ab(t_sclist *a, t_sclist *b)
{
	int			cheapest;
	t_sclist	*temp;

	temp = a;
	cheapest = ft_case_rrarrb_ab(a, b, temp->value);
	do
	{
		if (cheapest > ft_case_rarb_ab(a, b, temp->value))
			cheapest = ft_case_rarb_ab(a, b, temp->value);
		if (cheapest > ft_case_rrarrb_ab(a, b, temp->value))
			cheapest = ft_case_rrarrb_ab(a, b, temp->value);
		if (cheapest > ft_case_rarrb_ab(a, b, temp->value))
			cheapest = ft_case_rarrb_ab(a, b, temp->value);
		if (cheapest > ft_case_rrarb_ab(a, b, temp->value))
			cheapest = ft_case_rrarb_ab(a, b, temp->value);
		temp = temp->next;
	} while (temp != a);
	return (cheapest);
}
