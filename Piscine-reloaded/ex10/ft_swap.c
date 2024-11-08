/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:10:26 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/05 13:22:48 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

// #include <stdio.h>

// int	main(void)
// {
// 	int first = 42;
// 	int second = 36;
// 	int *ptr1;
// 	int *ptr2;

// 	ptr1 = &first;
// 	ptr2 = &second;

// 	ft_swap(ptr1, ptr2);
// 	printf("first %d, second %d", first, second);
// }