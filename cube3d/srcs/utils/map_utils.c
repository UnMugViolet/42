/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:14:23 by yguinio           #+#    #+#             */
/*   Updated: 2025/06/03 13:42:15 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	ft_is_charset(char c, char *charset)
{
	if (charset)
	{
		while (*charset)
		{
			if (*charset == c)
				return (true);
			charset++;
		}
	}
	return (false);
}
