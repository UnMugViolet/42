/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:48:26 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/13 14:22:15 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	str_size;

	str_size = ft_strlen(str);
	ptr = (char *)malloc(sizeof(char) * (str_size + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str, (str_size + 1));
	return (ptr);
}
