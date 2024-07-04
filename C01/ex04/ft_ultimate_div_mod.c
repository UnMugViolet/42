/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:09:01 by pjaguin           #+#    #+#             */
/*   Updated: 2024/06/30 11:36:43 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *a / *b;
	*b = temp % *b;
}

/*int	main(void)
{
	int first;
	int second;
	int *a;
	int *b;

	a = &first;
	b = &second;
	first = 100;
	second = 3;
	ft_ultimate_div_mod(a, b);
	printf("Value of a= %i, Value of b=%i\n", first, second);
	printf("Value  of the division: %i, Value of the modulo: %i", *a, *b);
	return (0);
} */