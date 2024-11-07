/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:49:52 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/17 17:15:19 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_in_base(char c, char *str);
int		ft_check_base_size(char *str);
int		is_whitespace(char c);
char	*ft_reverse(char *str);
int		ft_nbr_len(long nbr, int base_len);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int					i;
	int					is_negative;
	int					number;
	const unsigned int	base_size = ft_check_base_size(base);

	i = 0;
	is_negative = 1;
	number = 0;
	if (base_size < 2)
		return (0);
	while (is_whitespace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_negative *= -1;
		i++;
	}
	while (get_in_base(str[i], base) != -1)
	{
		number = (number * base_size) + get_in_base(str[i], base);
		i++;
	}
	return (number * is_negative);
}

char	*ft_itoa(int nbr, char *base)
{
	int			i;
	long		nb;
	int const	base_size = ft_strlen(base);
	char		*str_nbr;

	nb = nbr;
	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		str_nbr = (char *)malloc(sizeof(char) * ft_nbr_len(nb, base_size) + 2);
	}
	else
		str_nbr = (char *)malloc(sizeof(char) * ft_nbr_len(nb, base_size) + 1);
	while (nb >= base_size)
	{
		str_nbr[i] = base[nb % base_size];
		nb /= base_size;
		i++;
	}
	str_nbr[i++] = base[nb % base_size];
	if (nbr < 0)
		str_nbr[i++] = '-';
	str_nbr[i] = 0;
	return (ft_reverse(str_nbr));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!ft_check_base_size(base_from) || !ft_check_base_size(base_to))
	{
		base_to = NULL;
		return (base_to);
	}
	return (ft_itoa(ft_atoi_base(nbr, base_from), base_to));
}

/* #include <stdio.h>

int	main(int ac, char **av)
{
	char *base = av[2];
	(void)ac;
	printf("%s\n", ft_convert_base(av[1], av[2], av[3]));

	printf("Number using atoi base: %i\n", ft_atoi_base(av[1], base));
	printf("Number itoa: %s\n", ft_itoa(ft_atoi_base(av[1], base), base));
} */