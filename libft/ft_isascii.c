/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:25:53 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/12 16:18:18 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int	ft_isascii(int c)
{
	if (c < 0 || c > 127)
		return (1);
	return (0);
}
