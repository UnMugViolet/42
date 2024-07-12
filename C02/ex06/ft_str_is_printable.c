/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:48:25 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/03 13:37:44 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < 32 || str[i] == 127)
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
	char str[] = "";

	if (ft_str_is_printable(str) == 0)
	{
		printf("Something ain't right");
	}
	else
	{
		printf("Wszysko dobje || string maay be empty");
	}
} */