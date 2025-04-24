/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:26:03 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/21 16:40:53 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bases.h"

static char	*ft_fill_string(char *str, char *base, size_t nbr, int n)
{
	size_t	i;
	size_t	base_size;

	i = 0;
	base_size = ft_strlen(base);
	while (nbr >= base_size)
	{
		str[i] = base[nbr % base_size];
		nbr /= base_size;
		i++;
	}
	str[i++] = base[nbr % base_size];
	if (n < 0)
		str[i++] = '-';
	str[i] = 0;
	return (str);
}

char	*ft_itoa_base(int n, char *base)
{
	size_t	nbr;
	size_t	base_size;
	char	*str;
	int		buf;

	nbr = n;
	buf = 1;
	base_size = ft_strlen(base);
	if (n < 0)
	{
		nbr *= -1;
		buf = 2;
	}
	str = (char *)malloc(sizeof(char) * ft_nbrlen_base(nbr, base_size) + buf);
	if (!str)
		return (NULL);
	return (ft_reverse(ft_fill_string(str, base, nbr, n)));
}
