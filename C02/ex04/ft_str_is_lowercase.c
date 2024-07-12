/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:14:07 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/03 13:39:21 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < 'a' || str[i] > 'z')
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
	char str[] = "qwertyuiopasdfghjklzxcvbnm";
	ft_str_is_lowercase(str);

	if (ft_str_is_lowercase(str) == 0)
	{
		printf("String does not contain only lowercase");
	}
	else
	{
		printf("All guuuuud || string may be empty");
	}
} */