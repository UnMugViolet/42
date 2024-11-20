/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:24:00 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/20 18:15:10 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;
	size_t	print_len;

	va_start (ap, str);
	i = 0;
	print_len = 0;
	while (str[i++])
	{
		if (ft_strchr(str + i, '%'))
			print_len += ft_count_putchar_fd(str[i + 1], 1);
	}
	return (print_len);
}

int	main(void)
{
	char c = 'Q';
	ft_printf("%c", c);
}

