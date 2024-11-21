/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:24:00 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/21 11:26:46 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf_includes/ft_printf.h"

#include <stdio.h>

char	ft_check_type(va_list args, char c)
{
	size_t	print_len;

	print_len = 0;
	if (c == 'c')
		print_len += ft_count_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		print_len += ft_count_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'd' || c == 'i')
		print_len += ft_print_number_count(va_arg(args, int));
	else if (c == '%')
		print_len += ft_count_putchar_fd('%', 1);
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	print_len;
	size_t	i;

	va_start (args, str);
	i = -1;
	print_len = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			print_len += ft_check_type(args, str[i + 1]);
			i++;
		}
		else
			print_len += ft_count_putchar_fd(str[i], 1);
	}
	va_end(args);
	return (print_len);
}

int	main(void)
{
	// Test sting || %%
/* 	char test[] = "C";
	
	int	ft_result = (ft_printf("ft_printf: %s\n", test)-3);
	int	result = printf("printf: %s\n", test);
	
	printf("Int result ft_printf : %i\n", ft_result);
	printf("Int result printf: %i\n", result); */

	// Test numbers 
	int test = -215484851;
	
	int	ft_result = (ft_printf("ft_printf: %i\n", test)-3);
	int	result = printf("printf: %i\n", test);
	
	printf("Int result ft_printf : %i\n", ft_result);
	printf("Int result printf: %i\n", result);
}

