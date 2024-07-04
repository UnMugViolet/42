/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:44:35 by pjaguin           #+#    #+#             */
/*   Updated: 2024/06/27 19:30:24 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_alphabet(void)
{
	char	start_letter;
	char	end_letter;

	start_letter = 97;
	end_letter = 122;
	while (start_letter <= end_letter)
	{
		ft_putchar(start_letter);
		start_letter++;
	}
}

/* int	main(void)
{
	ft_print_alphabet();
} */