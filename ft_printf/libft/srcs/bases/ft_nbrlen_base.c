/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:36:26 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/21 16:20:32 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bases.h"

size_t	ft_nbrlen_base(size_t nbr, int base_len)
{
	size_t	i;

	i = 0;
	while (nbr / base_len > 0)
	{
		nbr /= base_len;
		i++;
	}
	return (i + 1);
}
