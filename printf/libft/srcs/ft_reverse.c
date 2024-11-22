/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:16:13 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/21 13:16:45 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
