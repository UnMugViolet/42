/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:00:12 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/11 11:06:33 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	fac_nb;

	fac_nb = nb - 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (fac_nb)
	{
		nb = nb * fac_nb;
		fac_nb--;
	}
	return (nb);
}

/* #include <stdio.h>

int	main(void)
{
	int	number;

	number = 6;
	ft_iterative_factorial(number);
	printf("%i", ft_iterative_factorial(number));
} */
