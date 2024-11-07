/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:37:35 by pjaguin           #+#    #+#             */
/*   Updated: 2024/06/30 14:30:53 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	r;

	i = 0;
	r = size - 1;
	while (i <= r)
	{
		ft_swap(&tab[i], &tab[r]);
		r--;
		i++;
	}
}

/*int	main(void)
{
	int tab[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int size = 10;
	int i = 0;
	int r = size - 1;

	ft_rev_int_tab(tab, size);

	while (i <= r)
	{
		printf("%i ", tab[i]);
		i++;
	}

	return (0);
} */