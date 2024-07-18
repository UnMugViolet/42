/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:34:32 by rxue              #+#    #+#             */
/*   Updated: 2024/07/14 18:42:22 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>
/*
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
}*/

void	ft_under_twenty(int n, t_dict *tab, int *first)
{
	ft_print_val(n, tab, first);
}

void	ft_decimals_process(int n, t_dict *tab, int *first)
{
	int	base;

	base = 90;
	while (base >= 20)
	{
		if (n / base > 0)
		{
			ft_print_val(base, tab, first);
			if (n % base != 0)
				ft_under_twenty(n % base, tab, first);
			break ;
		}
		else
			base -= 10;
	}
	if (base < 20)
		ft_under_twenty(n, tab, first);
}

void	ft_hundreds(int n, t_dict *tab, int *first)
{
	if (n / 100 != 0)
	{
		ft_print_val(n / 100, tab, first);
		ft_print_val(100, tab, first);
	}
	if (n % 100 != 0)
		ft_decimals_process(n % 100, tab, first);
}

void	ft_over_hundred(int n, t_dict *tab, int *first)
{
	int	base;

	base = 1000;
	while (base <= 1000000000 && base >= 1000)
	{
		if (n / 1000 == 0)
		{
			if (n / 100 != 0)
				ft_hundreds(n, tab, first);
			break ;
		}
		else
		{
			if (n / base > 0)
				base *= 1000;
			else
			{
				base /= 1000;
				ft_hundreds(n / base, tab, first);
				ft_print_val(base, tab, first);
				ft_over_hundred(n % base, tab, first);
				break ;
			}
		}
	}
}

void	ft_process_number(int n, t_dict *tab)
{
	int	*ptr;
	int	first;

	first = 1;
	ptr = &first;
	if (n < 100)
	{
		if (n < 20)
			ft_under_twenty(n, tab, ptr);
		else
			ft_decimals_process(n, tab, ptr);
	}
	else
		ft_over_hundred(n, tab, ptr);
}
