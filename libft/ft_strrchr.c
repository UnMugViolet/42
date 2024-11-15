/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:58:23 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/15 17:27:38 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*last_find;

	i = 0;
	last_find = NULL;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			last_find = (char *)(str + i);
		i++;
	}
	if (c == 0)
		return ((char *)(str + i));
	return (last_find);
}
