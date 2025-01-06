/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:11:12 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/18 19:44:20 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ptr;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (!s1[start])
	{
		ptr = (char *)malloc(sizeof(char) * 1);
		*ptr = 0;
		return (ptr);
	}
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	if (start > end)
		return (ft_strdup(s1 + end + 1));
	while (ft_strchr(set, s1[end]))
		end--;
	ptr = malloc(end - start + 2);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s1[start], end - start + 2);
	return (ptr);
}
