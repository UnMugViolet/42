/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:11:52 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/15 09:11:38 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int	ft_check_func_is(int(ft)(int), int(oem)(int), char *ft_name)
{
	int	i;
	int	end;

	i = -10;
	end = 120;
	while (i <= end)
	{
		if (ft(i) == oem(i))
			printf("✅ Alles gut for %s values: %i and %i\n ", ft_name, ft(i),
				oem(i));
		else if (ft(i) > 0 && oem(i) > 0)
			printf("✅ Alles gut for %s values: %i and %i\n ", ft_name, ft(i),
				oem(i));
		else
		{
			printf("❌ Error with %s values: %i and %i for i: %i\n", ft_name,
				ft(i), oem(i), i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(void)
{
	/* 	if (!ft_check_func_is(ft_isalnum, isalnum, "ft_isalnum"))
			return (0);
		if (!ft_check_func_is(ft_isalpha, isalpha, "ft_isalpha"))
			return (0);
		if (!ft_check_func_is(ft_isascii, isascii, "ft_isascii"))
			return (0); */

	const char s1[] = "___Cornichons___?dwq__?";
	char s2 = '_';
	char **result = ft_split(s1, s2);
	size_t count = 3;

	for (size_t i = 0; i < count; i++)
	{
		printf("%s\n", result[i]);
	}
	return (0);
}
