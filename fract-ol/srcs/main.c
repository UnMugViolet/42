/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:50:04 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/07 15:36:14 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int ac, char **av)
{
	t_engine	engine;

	(void)av;
	if (ac != 2)
		return (ft_display_usage(), EXIT_FAILURE);
	ft_init_engine(&engine, av[1]);
}
