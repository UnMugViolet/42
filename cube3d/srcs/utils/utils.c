/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:57:30 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/27 15:16:47 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_display_usage(void)
{
	ft_printf("Usage: ./cube3d <map.cub>\n");
}

void	print_err_exit(char *err_msg, char *arg, bool exiting)
{
	if (err_msg)
		while (*err_msg)
			write(2, err_msg++, 1);
	if (arg)
		while (*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
	if (exiting)
		exit(1);
}

