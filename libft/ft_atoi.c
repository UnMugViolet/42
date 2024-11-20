/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:58:04 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/20 11:22:49 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_overflowing(long number, int is_negative)
{
	if (is_negative == 1 && number > 2147483647)
		return (1);
	else if (is_negative == -1 && number > 2147483648)
		return (1);
	else
		return (0);
}

static int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
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
	while (is_whitespace(str[i]))
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
