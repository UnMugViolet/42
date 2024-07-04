/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:06:04 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/04 16:33:23 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned int)s1[i] - (unsigned int)s2[i]);
		}
		i++;
	}
	return ((unsigned int)s1[i] - (unsigned int)s2[i]);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str1[] = "carrottes";
	char	str2[] = "choux";
	int	result;

	result = ft_strcmp(str1, str2);

	printf("%i", result);
	return (0);
} */
