/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sclst_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:20:17 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/10 11:07:52 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	ft_sclst_max(t_sclist *sclist)
{
	t_sclist	*begin;
	int			max;

	begin = sclist;
	max = sclist->value;
	if (!sclist)
		return (0);
	while (sclist->next != begin)
	{
		sclist = sclist->next;
		if (sclist->value > max)
			max = sclist->value;
	}
	return (max);
}
