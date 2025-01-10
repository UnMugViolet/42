/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sclst_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:26:44 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/10 11:11:27 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

size_t	ft_sclst_size(t_sclist *sclist)
{
	t_sclist	*begin;
	size_t		count;

	begin = sclist;
	if (!sclist)
		return (0);
	count = 1;
	while (sclist->next != begin)
	{
		sclist = sclist->next;
		count++;
	}
	return (count);
}
