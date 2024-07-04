/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:00:05 by pjaguin           #+#    #+#             */
/*   Updated: 2024/06/27 19:32:23 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(void)
{
	char	incremented_figure;
	char	end_figure;

	incremented_figure = 48;
	end_figure = 57;
	while (incremented_figure <= end_figure)
	{
		ft_putchar(incremented_figure);
		incremented_figure++;
	}
}

/* int	main()
{
	ft_print_numbers();
} */