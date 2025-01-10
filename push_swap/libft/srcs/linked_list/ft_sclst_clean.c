/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sclst_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:57:22 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/10 11:07:39 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_sclst_clean(t_sclist **sclst)
{
	t_sclist	*tmp;
	t_sclist	*begin;

	begin = *sclst;
	while ((*sclst)->next != begin)
	{
		tmp = *sclst;
		*sclst = (*sclst)->next;
		free(tmp);
	}
	free(*sclst);
	free(sclst);
}
