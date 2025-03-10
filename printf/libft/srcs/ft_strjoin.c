/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:33:10 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/13 15:58:19 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ptr)
		return (NULL);
	while (i < (s1_len + s2_len))
	{
		while (i < s1_len)
		{
			ptr[i] = s1[i];
			i++;
		}
		ptr[i] = s2[i - s1_len];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
