/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:17:50 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/06 14:29:20 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ps_includes/push_swap.h"

int	main(int ac, char **av)
{
	ft_printf("Args count : %s\n",ft_itoa(ac));
	if (!is_correct_input(av, ac))
		return (-1);
	return (0);
}
