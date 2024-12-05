/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:11:52 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/20 11:29:28 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

/* int	ft_check_func_is(int(ft)(int), int(oem)(int), char *ft_name)
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
} */

char f(unsigned int i, char c)
{
	char str;
	i = 1;
	str = c + i;
	return (str);
}

int	main(void)
{
	/* 	if (!ft_check_func_is(ft_isalnum, isalnum, "ft_isalnum"))
			return (0);
		if (!ft_check_func_is(ft_isalpha, isalpha, "ft_isalpha"))
			return (0);
		if (!ft_check_func_is(ft_isascii, isascii, "ft_isascii"))
			return (0); */

/* 	// Test atoi
	char str[] = "-21474836505454";
	printf("custom gives: %i\n", ft_atoi(str));
	printf("atoi gives: %i", atoi(str)); */
/* 	// Test substr
	printf ("%s", ft_substr("hola", 4294967295, 0));
	return (0); */
/* 	// Test strtrim
	char src[] = "";
	char set[] = "";
	
	char *result = ft_strtrim(src, set);
	printf("%s\n", result); */
	

	/* 	// Test strlcat
	char src[] = "AAAAAAAAA";
	char dest[] = "B";
	
	int result = ft_strlcat(dest, src, 1);
	printf("%i", result);
	 */
	
	// Test split 
	const char s1[] = "  tripouille  42  ";
	char s2 = ' ';
	char **result = ft_split(s1, s2);
	size_t count = 3;

	for (size_t i = 0; i < count; i++)
	{
		printf("%s\n", result[i]);
	}
	return (0);

/* 	// Test ft_itoa
	int	nbr = -214748364;
	char *result = ft_itoa(nbr);

	printf("%s\n", result); */


/* 	// Test ft_strmapi
	char str1[] = "abc";
	char* str2;
	str2 = ft_strmapi(str1, *f);
	printf("%s\n", str2); 
	for (size_t i = 0; i < 4; i++)
		printf("%i\n", str2[i]);
	 */

/* 	// Test ft_putchar_fd
	ft_putchar_fd('C', 1); */

/* 	// Test ft_putstr_fd
	ft_putstr_fd("Marmite, c'est un mot rigolo tout de même", -1); */

/* 	// Test ft_putendl_fd
	ft_putendl_fd("Chaussons aussi c'est marrant", 1); */

/* 	// Test de ft_putnbr_fd
	int	n = -2147483648;
	int fd = 1;
	ft_putnbr_fd(n, fd); */
}
