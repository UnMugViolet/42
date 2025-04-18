/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:00:49 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/18 09:20:18 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_print_str(char *str, int fd)
{
	while (*str)
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
}

void	ft_putstr_fd(char *str, int fd)
{
	if (fd == ERR_OUT)
	{
		ft_print_str(RED, fd);
		ft_print_str(BOLD, fd);
		ft_print_str(str, fd);
		ft_print_str(RESET, fd);
	}
	else
	{
		ft_print_str(BOLD, fd);
		ft_print_str(str, fd);
		ft_print_str(RESET, fd);
	}
}
