/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:06:08 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/25 14:43:53 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf_includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	// Hardcore tests
/* 	int i;
	char *str;
	void *ptr;
	int j;

	i = -2147483648;
	ft_printf("int min :\n");
	ft_printf("<-ft : %d\n", ft_printf("%d", i));
	printf("<-OG : %d\n", printf("%d", i));
	str = NULL;
	ft_printf("str NULL :\n");
	ft_printf("<-ft : %d\n", ft_printf("%s", str));
	printf("<-OG : %d\n", printf("%s", str));
	ptr = NULL;
	ft_printf("ptr NULL :\n");
	ft_printf("<-ft : %d\n", ft_printf("%p", str));
	printf("<-OG : %d\n", printf("%p", str));
	ft_printf("guillemets :\n");
	ft_printf("<-ft : %d\n", ft_printf(""));
	printf("<-OG : %d\n", printf(""));
	ft_printf("ft_printf(0) :\n");
	ft_printf("<-ft : %d\n", ft_printf(0));
	printf("<-OG : %d\n", printf(0));
	ft_printf("pourcent :\n");
	ft_printf("<-ft : %d\n", ft_printf("%%"));
	printf("<-OG : %d\n", printf("%%"));
	str = "les loulous";
	ptr = str;
	ft_printf("differents flags au milieu d'un phrase :\n");
	ft_printf("<-ft : %d\n", ft_printf("%p Salut %s l'int %% min vaut %d au revoir %s", ptr, str, i, str));
	printf("<-OG : %d\n", printf("%p Salut %s l'int %% min vaut %d au revoir %s", ptr, str, i, str));
	i = 42;
	ft_printf("print X :\n");
	ft_printf("<-ft : %d\n", ft_printf("%X", i));
	printf("<-OG : %d\n", printf("%X", i));
	ft_printf("print x :\n");
	ft_printf("<-ft : %d\n", ft_printf("%x", i));
	printf("<-OG : %d\n", printf("%x", i));
	j = -2147483648;
	ft_printf("print u :\n");
	ft_printf("<-ft : %d\n", ft_printf("%u", j));
	printf("<-OG : %d\n", printf("%u", j)); */

	
	// Dumb test
/* 	printf(0);
	ft_printf(0); */
	
	// Test string || %%
/* 	char *test = "Le Lorem Ipsum est simplement du faux texte employé dans la composition et la mise en page avant impression. Le Lorem Ipsum est le faux texte standard de l'imprimerie depuis les années 1500, quand un imprimeur anonyme assembla ensemble des morceaux de texte pour réaliser un livre spécimen de polices de texte. Il n'a pas fait que survivre cinq siècles, mais s'est aussi adapté à la bureautique informatique, sans que son contenu n'en soit modifié. Il a été popularisé dans les années 1960";
	
	printf("Length: %zu\n", ft_strlen(test));
	int	ft_result = (ft_printf("printf: %s\n", test));
	int	result = (printf("printf: %s\n", test));

	printf("Int result ft_printf : %i\n", ft_result);
	printf("Int result printf: %i\n", result); */

	// Test pointer
/* 	char *test = "test";
	char *test2 = "test2";
	
	int	ft_result = (ft_printf("ft_printf: %p %p\n", test, test2)-3);
	int	result = printf("printf: %p %p\n", test, test2);
	
	printf("Int result ft_printf : %i\n", ft_result);
	printf("Int result printf: %i\n", result); */

	// Test ints 
/* 	long test = -2147483649;
	
	int	ft_result = (ft_printf("ft_printf: %i\n", test)-3);
	int	result = printf("printf: %i\n", test);
	
	printf("Int result ft_printf : %i\n", ft_result);
	printf("Int result printf: %i\n", result); */

	// Test unsigned ints
/* 	unsigned int test = 0;
	
	unsigned int	ft_result = (ft_printf("ft_printf: %u\n", test)-3);
	unsigned int	result = printf("printf: %u\n", test);
	
	printf("Int result ft_printf : %u\n", ft_result);
	printf("Int result printf: %u\n", result); */

	// Test hexa
/* 	unsigned int test = -10;

	// unsigned int	ft_result = (ft_printf("ft_printf: %x\n", test)-3);
	// unsigned int	result = printf("printf: %x\n", test);

	unsigned int	ft_result = (ft_printf("ft_printf: %X\n", test)-3);
	unsigned int	result = printf("printf: %X\n", test);

	printf("Int result ft_printf : %u\n", ft_result);
	printf("Int result printf: %u\n", result); */
}
