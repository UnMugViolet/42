/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:38:28 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/05 14:53:55 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// #include <stdio.h>

// int		main(void)
// {
// 	int	a = 100;
// 	int	b = 4;
// 	int	c;
// 	int	d;
// 	int	*div = &c;
// 	int	*mod = &d;

// 	ft_div_mod(a, b, div, mod);
// 	printf("Value of a= %i, Value of b=%i\n", a, b);
// 	printf("Value  of the division: %i, Value of the modulo: %i", *div, *mod);
// 	return (0);
// }