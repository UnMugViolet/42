/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:00:25 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/02 19:48:21 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
			i++;
		}
		else
		{
			i++;
		}
	}
	return (str);
}

/* #include <stdio.h>

int	main(void)
{
	char str[] = "QWERTYUIOPASDFGHJKLZXCVBNM1234567890!@#$%^&*()_+-=`";

	ft_strupcase(str);

	printf("%s", str);
} */