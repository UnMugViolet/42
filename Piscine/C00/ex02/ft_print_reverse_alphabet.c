/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:34:52 by pjaguin           #+#    #+#             */
/*   Updated: 2024/06/27 19:31:14 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_reverse_alphabet(void)
{
	char	start_letter;
	char	end_letter;

	start_letter = 122;
	end_letter = 97;
	while (start_letter >= end_letter)
	{
		ft_putchar(start_letter);
		start_letter--;
	}
}

/* int	main()
{
	ft_print_reverse_alphabet();
} */