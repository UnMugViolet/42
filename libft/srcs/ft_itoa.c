/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:59:40 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/21 16:41:07 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill_string(char *str, unsigned long nbr, int n)
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
	unsigned long	nbr;
	char			*str;
	int				buffer;

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
