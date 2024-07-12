/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:59:40 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/03 13:07:16 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < 'A' || str[i] > 'Z')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/* #include <stdio.h>

int	main(void)
{
	char str[] = "QWERTYUIOPASDFGHJKLZXCVBNM@";
    int result;

	result = ft_str_is_uppercase(str);

    printf("%i", result);
} */