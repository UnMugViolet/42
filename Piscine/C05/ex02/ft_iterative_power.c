/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:34:04 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/11 11:06:43 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	nb_const;

	nb_const = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power - 1)
	{
		nb *= nb_const;
		power--;
	}
	return (nb);
}

/* #include <stdio.h>

int	main(void)
{
	printf("%i", ft_iterative_power(3, 5));
} */