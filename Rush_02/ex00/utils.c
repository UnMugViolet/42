/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:30:27 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/14 18:17:20 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_print(unsigned int output, char *str, unsigned int newline)
{
	write(output, str, ft_strlen(str));
	if (newline)
		write(output, "\n", 1);
}

unsigned long	ft_atoi(char *str)
{
	unsigned long	result;
	int				sign;
	int				i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' \
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	i = 0;
	if (dest == 0)
		return (0);
	else
	{
		while (str[i] != '\0')
		{
			dest[i] = str[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
