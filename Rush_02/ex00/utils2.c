/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:13:18 by rxue              #+#    #+#             */
/*   Updated: 2024/07/14 18:21:12 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>

void	ft_print_val(int n, t_dict *tab, int *first)
{
	int	i;

	i = 0;
	while (tab[i].val != 0)
	{
		if (n == tab[i].nbr)
		{
			if (!*first)
				write(1, " ", 1);
			else
				*first = 0;
			ft_putstr(tab[i].val);
			break ;
		}
		i++;
	}
}
