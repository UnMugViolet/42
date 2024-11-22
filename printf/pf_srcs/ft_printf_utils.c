/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:02:11 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/22 12:21:28 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf_includes/ft_printf.h"

int	ft_print_string_count(char *str, int fd)
{
	if (!str)
		return (ft_count_putstr_fd("(null)", fd));
	return (ft_count_putstr_fd(str, fd));
}

int	ft_print_number_count(int n)
{
	char	*nbr_str;
	int		len;

	nbr_str = ft_itoa(n);
	ft_count_putstr_fd(nbr_str, 1);
	len = ft_strlen(nbr_str);
	free(nbr_str);
	return (len);
}

int	ft_print_unsigned_count(unsigned int n)
{
	char	*nbr_str;
	int		len;

	nbr_str = ft_uitoa(n);
	ft_count_putstr_fd(nbr_str, 1);
	len = ft_strlen(nbr_str);
	free(nbr_str);
	return (len);
}

int	ft_count_putptr_fd(unsigned long int ptr, int fd)
{
	size_t	len;
	char	*base;
	char	*str;

	base = "0123456789abcdef";
	if (!ptr)
		return (ft_count_putstr_fd("(nil)", fd));
	len = ft_count_putstr_fd("0x", fd);
	str = ft_ulitoa_base(ptr, base);
	len += ft_count_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	ft_count_putnbr_base_fd(unsigned int nbr, char type, int fd)
{
	size_t	len;
	size_t	i;
	char	*str;
	char	*base;
	int		base_modified;

	i = 0;
	base_modified = 0;
	base = "0123456789abcdef";
	if (type == 'X')
	{
		base = ft_str_toupper(base);
		base_modified = 1;
	}
	str = ft_uitoa_base(nbr, base);
	len = ft_strlen(str);
	ft_putstr_fd (str, fd);
	free(str);
	if (base_modified)
		free(base);
	return (len);
}
