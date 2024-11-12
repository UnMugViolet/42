/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:11:52 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/12 10:22:56 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

int	ft_check_func_is(int(ft)(int), int(oem)(int), char *ft_name)
{
	int	i;
	int	end;

	i = -10;
	end = 120;
	while (i <= end)
	{
		if (ft(i) == oem(i))
			printf("✅ Alles gut for %s values: %i and %i\n ", ft_name, ft(i), oem(i));
		else if (ft(i) > 0 && oem(i) > 0)
			printf("✅ Alles gut for %s values: %i and %i\n ", ft_name, ft(i), oem(i));
		else
		{
			printf("❌ Error with %s values: %i and %i for i: %i\n", ft_name, ft(i), oem(i), i);
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

	char *str = "Yolo";
	size_t  n = 1;

	ft_bzero(str, n);

	printf("%s", str);
}