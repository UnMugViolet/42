/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:02:11 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/21 11:28:58 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf_includes/ft_printf.h"

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
