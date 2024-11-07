/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:22:55 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/06 10:51:19 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	array = (int *)malloc(sizeof(int) * (max - min));
	while (i < max)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}

/* #include <stdio.h>

int	main(void)
{
	int i = 0;
	int min = 0;
	int max = 1;
	int size = max - min;
	while (i < size)
	{
		printf("%d ", ft_range(min, max)[i]);
		i++;
	}
	free(ft_range(min, max));
	return (0);
} */