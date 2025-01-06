/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:43:12 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/21 17:49:04 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_toupper(char *str)
{
	size_t	i;
	char	*ptr;

	i = -1;
	if (!str)
		return (NULL);
	ptr = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!ptr)
		return (NULL);
	while (str[++i])
		ptr[i] = ft_toupper(str[i]);
	ptr[i] = 0;
	return (ptr);
}
