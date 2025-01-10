/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sclst_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:59:22 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/10 11:04:10 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include "ft_printf.h"

void	ft_sclst_print(t_sclist **sclst)
{
	t_sclist	*temp;

	temp = *sclst;
	if (!sclst || !(*sclst))
		return ;
	while (temp->next != (*sclst))
	{
		ft_printf("sclst value: %i\naddress: %p\n", temp->value, temp);
		temp = temp->next;
	}
	ft_printf("Pointed by last: %i\naddress: %p\n", temp->value, temp->next);
}
