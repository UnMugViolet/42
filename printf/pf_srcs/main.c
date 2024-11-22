/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:06:08 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/22 13:30:41 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf_includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
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
