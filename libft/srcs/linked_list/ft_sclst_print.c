/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sclst_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:59:22 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/10 17:47:41 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include "ft_printf.h"

void	ft_sclst_print(t_sclist **sclst, char c)
{
	t_sclist	*temp;

	temp = *sclst;
	if (!sclst || !(*sclst))
		return ;
	while (temp->next != (*sclst))
	{
		ft_printf("%c: value: %i\n", c, temp->value);
		temp = temp->next;
	}
	ft_printf("%c: value: %i\n\n", c, temp->value);
}
