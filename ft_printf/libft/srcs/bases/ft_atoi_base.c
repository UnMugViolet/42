/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:10:56 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/21 15:44:02 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bases.h"

int	ft_atoi_base(char *str, char *base)
{
	size_t			i;
	int				is_negative;
	int				number;
	const size_t	base_size = ft_check_base_size(base);

	i = 0;
	is_negative = 1;
	number = 0;
	if (base_size < 2)
		return (0);
	while (ft_is_whitespace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_negative *= -1;
		i++;
	}
	while (ft_get_in_base(str[i], base))
	{
		number = (number * base_size) + ft_get_in_base(str[i], base);
		i++;
	}
	return (number * is_negative);
}
