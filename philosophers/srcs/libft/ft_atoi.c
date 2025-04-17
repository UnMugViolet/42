/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:58:04 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/16 15:12:48 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	is_overflowing(long number, int is_negative)
{
	if (is_negative == 1 && number > 2147483647)
		return (1);
	else if (is_negative == -1 && number > 2147483648)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	size_t			i;
	int				is_negative;
	unsigned long	number;

	i = 0;
	number = 0;
	is_negative = 1;
	while (ft_is_whitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_negative *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		number *= 10;
		number += str[i] - '0';
		if (is_overflowing(number, is_negative))
			return (0);
		i++;
	}
	return (number * is_negative);
}
