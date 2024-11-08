/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:22:55 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/08 10:40:18 by pjaguin          ###   ########.fr       */
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
	if (!array)
		return (NULL);
	while (i < (max - min))
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
	int min = -10;
	int max = 20;
	int size = max - min;
	while (i < size)
	{
		printf("%d ", ft_range(min, max)[i]);
		i++;
	}
	free(ft_range(min, max));
	return (0);
} */