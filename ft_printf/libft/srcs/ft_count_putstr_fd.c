/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_putstr_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:47:36 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/22 12:25:22 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_putstr_fd(char *str, int fd)
{
	size_t	i;

	i = -1;
	while (str[++i])
		ft_putchar_fd(str[i], fd);
	return (i);
}
