/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:45:45 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/17 15:06:38 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	origin_size;

	i = 0;
	origin_size = ft_strlen(dest);
	while (src[i])
	{
		dest[i + origin_size] = src[i];
		i++;
	}
	dest[i + origin_size] = 0;
	return (dest);
}

int	get_full_size(char **strs, char *sep, int size)
{
	int	i;
	int	full_size;

	i = 0;
	full_size = 0;
	while (i < size)
	{
		full_size += ft_strlen(strs[i]);
		if (i < size - 1)
			full_size += (ft_strlen(sep));
		i++;
	}
	return (full_size + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		full_size;
	char	*str;

	i = 0;
	full_size = get_full_size(strs, sep, size);
	str = (char *)malloc(sizeof(char) * (full_size));
	if (!str)
		return (NULL);
	if (size == 0)
	{
		str[0] = 0;
		return (str);
	}
	*str = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i < size - 1)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}

/* #include <stdio.h>

int	main(int ac, char **av)
{
	char **f_string;
	f_string = (char **)malloc(sizeof(char *) * 2);
	if (!f_string)
		return (0);
	char *string = "Je suis alle a la boulangerie hier";
	char *sep= " / ";
	char *string2 = "J'ai mange un super sandwich, au poulet. Rotie";
	f_string[0] = string;
	f_string[1] = string2;

	(void)ac;
	(void)av;
	printf("%s", ft_strjoin(2, f_string, sep));
	free(f_string);
	return (0);
} */