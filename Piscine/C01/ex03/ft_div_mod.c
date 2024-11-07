/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:58:02 by pjaguin           #+#    #+#             */
/*   Updated: 2024/06/30 16:58:54 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int	main(void)
{
	int	a;
	int	b;
	int	*div;
	int	*mod;
	int	c;
	int	d;

	div = &c;
	mod = &d;
	a = 100;
	b = 3;
	ft_div_mod(a, b, div, mod);
	printf("Value of a= %i, Value of b=%i\n", a, b);
	printf("Value  of the division: %i, Value of the modulo: %i", *div, *mod);
	return (0);
} */
