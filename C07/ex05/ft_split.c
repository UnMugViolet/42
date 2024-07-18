/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:13:46 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/18 09:49:41 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_lenght(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (i);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	j;
	int	char_counter;

	i = 0;
	char_counter = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j] && str[i + 1] == charset[j])
				char_counter++;
			j++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	// Taille en char de la string a mallocer
	str = (char *)malloc(sizeof(char) * ft_count_words(str) + 1);
}

#include <stdio.h>

int	main(void)
{
	char str[] = "Split de merde la, vas y on peut pas s'arreter a strlen ?!";
	char charset[] = ",? ";
	ft_split(str, charset);
}