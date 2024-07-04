/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:40:47 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/02 16:11:59 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
	{
		return (1);
	}
	while (str[i] != 0)
	{
		if (str[i] < 48 || str[i] > 57)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
#include <stdio.h>

int	main(void)
{
	char str[] = "02258742";

	ft_str_is_numeric(str);

	if (ft_str_is_numeric(str) == 0)
	{
		printf("Crap alert, should be figures all the time");
	}
	else
	{
		printf("Goooood boy || string may be empty");
	}
} */