/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:59:40 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/15 14:27:31 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbr_len(long nbr)
{
	int	i;

	i = 0;
	while (nbr / 10 > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i + 1);
}

char	*ft_reverse(char *str)
{
	int		i;
	int		strlen;
	char	temp;

	strlen = ft_strlen(str);
	i = 0;
	while (i < strlen / 2)
	{
		temp = str[i];
		str[i] = str[strlen - 1 - i];
		str[strlen - 1 - i] = temp;
		i++;
	}
	return (str);
}

char	*ft_fill_string(char *str, long nbr, int n)
{
	size_t	i;

	i = 0;
	while (nbr >= 10)
	{
		str[i] = (nbr % 10) + '0';
		nbr /= 10;
		i++;
	}
	str[i++] = (nbr % 10) + '0';
	if (n < 0)
		str[i++] = '-';
	str[i] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*str;
	int		buffer;

	nbr = n;
	buffer = 1;
	if (n < 0)
	{
		buffer = 2;
		nbr *= -1;
	}
	str = (char *)malloc(sizeof(char) * ft_nbr_len(nbr) + buffer);
	if (!str)
		return (NULL);
	return (ft_reverse(ft_fill_string(str, nbr, n)));
}
