/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:11:12 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/13 17:26:32 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*ptr;

	i = -1;
	j = 0;
	len = ft_strlen(s1) - 1;
	while (is_in_set(((char *)s1)[len], (char *)set))
		len--;
	while (is_in_set(((char *)s1)[++i], (char *)set))
		len--;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (s1[i + j] && j <= len)
	{
		ptr[j] = s1[i + j];
		j++;
	}
	return (ptr);
}
