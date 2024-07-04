/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:14:07 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/02 18:23:24 by pjaguin          ###   ########.fr       */
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

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
	{
		return (1);
	}
	while (str[i] != 0)
	{
		if (str[i] <= 97 || str[i] >= 122)
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
	char str[] = "qwertyuiop";
	ft_str_is_lowercase(str);

	if (ft_str_is_lowercase(str) == 0)
	{
		printf("String does not contain only lowercase");
	}
	else
	{
		printf("All guuuuud");
	}
} */