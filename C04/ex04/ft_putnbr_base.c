/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:55:37 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/10 09:45:17 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_checkbase(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[j] == str[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	lnbr;
	int			base_size;

	lnbr = nbr;
	base_size = ft_checkbase(base);
	if (base_size < 2)
		return ;
	if (lnbr < 0)
	{
		ft_putchar('-');
		lnbr *= -1;
	}
	if (lnbr >= base_size)
	{
		ft_putnbr_base(lnbr / base_size, base);
	}
	lnbr = lnbr % base_size;
	write(1, &base[lnbr], 1);
}

/* int	main(void)
{
	char str[] = "01";
	ft_putnbr_base(10, str);
} */