/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:35:25 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/09 18:40:26 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\v'
		|| c == '\f')
		return (1);
	return (0);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	is_negative;
	int	number;

	i = 0;
	is_negative = 1;
	number = 0;
	while (is_whitespace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_negative *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	return (number * is_negative);
}

/* #include <stdio.h>

int	main(void)
{
	char	str[] = " ++++-----456j456";

	ft_atoi(str);
	printf("%i", ft_atoi(str));
	return (0);
} */