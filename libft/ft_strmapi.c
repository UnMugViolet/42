/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:32:44 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/15 14:58:01 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*ptr;

	i = 0;
	len = ft_strlen(str);
	ptr = (char *)malloc(sizeof(char *) * (sizeof(char) * (len + 1)));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = f(i, str[i]);
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
