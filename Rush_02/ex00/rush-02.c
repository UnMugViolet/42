/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:24:08 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/14 10:50:35 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	main(int argc, char **argv)
{
	int		nbr;
	t_dict	*tab;

	if (argc > 2 || argc < 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		tab = get_dict("numbers.dict");
		ft_process_number(nbr, tab);
	}
	else if (argc == 3)
	{
		nbr = ft_atoi(argv[2]);
		tab = get_dict(argv[1]);
		ft_process_number(nbr, tab);
	}
	return (0);
}
