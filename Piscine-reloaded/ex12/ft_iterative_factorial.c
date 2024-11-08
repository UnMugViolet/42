/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:53:33 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/05 16:37:00 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	count;

	count = nb - 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (count)
	{
		nb = nb * count;
		count--;
	}
	return (nb);
}

/* #include <stdio.h>

int	main(void)
{
	printf("%i", ft_iterative_factorial(0));
} */