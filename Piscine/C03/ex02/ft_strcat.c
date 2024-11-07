/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:31:53 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/04 14:45:03 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	origin_size;

	i = 0;
	origin_size = ft_strlen(dest);
	while (src[i] != 0)
	{
		dest[i + origin_size] = src[i];
		i++;
	}
	dest[i + origin_size] = 0;
	return (dest);
}

/* #include <unistd.h>

int	main(void)
{
	char	src[] = "Fumier";
	char	dest[] = "Bonjour ";
	char	*result;

	result = ft_strcat(dest, src);
	write(1, result, ft_strlen(result));
	return (0);
} */