/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:59:30 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/07 14:07:01 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str);

void	ft_print(unsigned int output, char *str, unsigned int newline)
{
	write(output, str, ft_strlen(str));
	if (newline)
		write(output, "\n", 1);
}

void	ft_print_dbl_tab(int **tab)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			nb = tab[i][j] + '0';
			write(1, &nb, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
