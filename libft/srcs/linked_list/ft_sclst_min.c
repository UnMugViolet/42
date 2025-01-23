/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sclst_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:20:24 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/14 14:48:31 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	ft_sclst_min(t_sclist *sclist)
{
	t_sclist	*begin;
	int			min;

	begin = sclist;
	if (!sclist)
		return (0);
	min = sclist->value;
	while (sclist->next != begin)
	{
		sclist = sclist->next;
		if (sclist->value < min)
			min = sclist->value;
	}
	return (min);
}
