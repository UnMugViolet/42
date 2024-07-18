/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:08:32 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/17 09:28:49 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	i;
	int	is_negative;
	int	number;

	i = 0;
	is_negative = 1;
	number = 0;
	if (str[0] == '-')
	{
		is_negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	return (number * is_negative);
}

int ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	range[0] = (int *)malloc(sizeof(int) * (max - min));
	if (!range)
		return (-1);
	while (min < max)
	{
		if (i == 0)
			range[0][0] = min;
		range[0][i] = min++;
		i++;
	}
	return (i);
}

/* #include <stdio.h>
int	main(int ac, char **av)
{
	int	**range;
	int	min = ft_atoi(av[1]);
	int	max = ft_atoi(av[2]);
	(void)av;
	int i = 0;

	range = (int **)malloc(sizeof(int *));
	if (ac != 3)
		return (0);

	ft_ultimate_range(range, min, max);

	printf("Number: %i\n", ft_ultimate_range(range, min, max));
	while (min < max)
	{
		printf("%i\n", range[0][i]);
		min++;
		i++;
	}

	free(range);
} */