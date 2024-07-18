/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:20:47 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/15 17:16:49 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	i;
	int	is_negative;
	int	number;

	i = 0;
	number = 0;
	is_negative = 1;
	if (str[0] == '-')
		is_negative *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	return (number * is_negative);
}

int	*ft_range(int min, int max)
{
	int	*array;
	int	i;

	i = 0;
	array = NULL;
	if (min >= max)
		return (array);
	array = (int *)malloc(sizeof(int) * (max - min));
	if (!array)
		return (NULL);
	while (min < max)
	{
		if (i == 0)
			array[0] = min;
		array[i] = min++;
		i++;
	}
	return (array);
}

/* int	main(int ac, char **av)
{
	int *array;
	int min;
	int max;

	min = ft_atoi(av[1]);
	max = ft_atoi(av[2]);
	long int i = 0;
	long int count = max - min;

	if (ac != 3)
		return (0);

	array = ft_range(min, max);

	for (i = 0; i < count; i++)
	{
		printf("%i\n", array[i]);
	}

	free(array);
} */