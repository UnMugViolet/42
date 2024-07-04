/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:17:12 by pjaguin           #+#    #+#             */
/*   Updated: 2024/06/28 11:58:08 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/* int	main(void)
{
	int	first;
	int	second;
	int	*ptr1;
	int	*ptr2;

	first = 87;
	second = 22;
	ptr1 = &first;
	ptr2 = &second;
	printf("Value before the swap: a = %d, b = %d\n", *ptr1, *ptr2);
	ft_swap(ptr1, ptr2);
	printf("Value after the swap: a = %d, b = %d \n", *ptr1, *ptr2);
	return (0);
} */