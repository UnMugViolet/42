/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:48:30 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/02 16:11:55 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) <= 0)
	{
		return (1);
	}
	while (str[i] != 0)
	{
		if (str[i] < 65 || str[i] > 122)
		{
			return (0);
		}
		if (str[i] > 90 && str[i] < 97)
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
	char str[] = "";
	ft_str_is_alpha(str);

	if (ft_str_is_alpha(str) == 0)
	{
		printf("There is a non alphabetical char");
	} else
	{
		printf("Alles gut || string may be empty");
	}
} */