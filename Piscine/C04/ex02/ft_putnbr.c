/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:37:48 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/10 09:53:29 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	nbr;

	nbr = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	nbr = nbr % 10;
	ft_putchar(nbr + '0');
}

/* int	main(void)
{
	ft_putnbr(-2147483648);
} */