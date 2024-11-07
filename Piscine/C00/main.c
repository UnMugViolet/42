/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 08:56:56 by pjaguin           #+#    #+#             */
/*   Updated: 2024/06/27 10:16:20 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// void    ft_putchar(char c);
// void    ft_print_alphabet();

int	main(void)
{
	char    one;
    one = 49;

	write(1, &one, 1);

	return (0);
}
