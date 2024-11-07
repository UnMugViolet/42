/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:05:46 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/04 14:45:21 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size < dest_len)
	{
		return (src_len + size);
	}
	if (size != 0)
	{
		while (src[i] != 0 && i < size - 1)
		{
			dest[i + dest_len] = src[i];
			i++;
		}
		dest[i + dest_len] = 0;
	}
	return (dest_len + src_len);
}

/* #include <bsd/string.h>
int	main(void)
{
	char src[] = "dddd";
	char dest[] = "eeee";
	unsigned int size = 9;
	unsigned int result;

	result = ft_strlcat(dest, src, size);

	printf("%i\n", result);
} */