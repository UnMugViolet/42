/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:33:01 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/17 17:10:44 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);

int	get_in_base(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_check_base_size(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[j] == str[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	is_whitespace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

char	*ft_reverse(char *str)
{
	int		i;
	int		strlen;
	char	temp;

	strlen = ft_strlen(str);
	i = 0;
	while (i < strlen / 2)
	{
		temp = str[i];
		str[i] = str[strlen - 1 - i];
		str[strlen - 1 - i] = temp;
		i++;
	}
	return (str);
}

int	ft_nbr_len(long nbr, int base_len)
{
	int	i;

	i = 0;
	while (nbr / base_len > 0)
	{
		nbr /= base_len;
		i++;
	}
	return (i + 1);
}
