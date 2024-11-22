/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_in_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:13:14 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/21 15:43:47 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bases.h"

size_t	ft_get_in_base(char c, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (0);
}
