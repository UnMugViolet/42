/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 08:21:10 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/02 19:46:03 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

int	ft_is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

char	is_anum(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	if (is_digit(c))
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (is_anum(str[i]) && ft_is_uppercase(str[i]))
		{
			str[i] = str[i] + 32;
		}
		if (!is_anum(str[i - 1]) && !ft_is_uppercase(str[i]))
		{
			if (is_anum(str[i]) && !is_digit(str[i]))
			{
				str[i] = str[i] - 32;
			}
		}
		i++;
	}
	return (str);
}

/* 
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	ft_strcapitalize(str);

	write(1, &str, ft_strlen(str));

	return (0);
} */