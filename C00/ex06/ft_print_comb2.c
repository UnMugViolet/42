/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:07:14 by pjaguin           #+#    #+#             */
/*   Updated: 2024/06/27 19:37:23 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	write_content(int translate)
{
	ft_putchar((translate / 10) + 48);
	ft_putchar((translate % 10) + 48);
}

void	format_render(int a, int b)
{
	if (a == 98 && b == 99)
	{
		write(1, "", 2);
	}
	else
	{	
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a <= 99)
	{
		while (b <= 99)
		{
			write_content(a);
			write(1, " ", 1);
			write_content(b);
			format_render(a, b);
			b++;
		}
		a++;
		b = a + 1;
	}
}

/* int	main(void)
{
	ft_print_comb2();
	return (0);
} */