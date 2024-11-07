/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:31:56 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/04 10:18:12 by pjaguin          ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i] != 0 && i < nb)
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[i + dest_len] = 0;
	return (dest);
}

/*#include <unistd.h>

int	main(void)
{
	char	src[] = "Truite";
	char	dest[] = "Sale ";
	int	size = 10;
	char	*result;
	int	total_lenght;

	result = ft_strncat(dest, src, size);

	total_lenght = ft_strlen(result);

	write(1, result, total_lenght);
}*/
