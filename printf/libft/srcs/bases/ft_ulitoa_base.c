/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:26:03 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/22 10:32:42 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bases.h"

static char	*ft_fill_string(char *str, char *base, unsigned long long nbr)
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
	str[i] = 0;
	return (str);
}

char	*ft_ulitoa_base(unsigned long int n, char *base)
{
	unsigned long long	nbr;
	size_t				base_size;
	char				*str;

	nbr = n;
	base_size = ft_strlen(base);
	str = (char *)malloc(sizeof(char) * ft_nbrlen_base(nbr, base_size) + 1);
	if (!str)
		return (NULL);
	return (ft_reverse(ft_fill_string(str, base, nbr)));
}
