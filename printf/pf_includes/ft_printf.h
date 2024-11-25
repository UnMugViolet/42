/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:49:30 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/25 11:28:23 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/bases.h"

int	ft_printf(const char *str, ...);
int	ft_print_string_count(char *str, int fd);
int	ft_print_number_count(int n);
int	ft_print_unsigned_count(unsigned int n);
int	ft_count_putptr_fd(unsigned long int ptr, int fd);
int	ft_count_putnbr_base_fd(unsigned int nbr, char type, int fd);

#endif
