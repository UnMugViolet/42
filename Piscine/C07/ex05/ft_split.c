/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:13:46 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/18 14:19:33 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count_words;
	int	is_word;

	is_word = 0;
	i = 0;
	count_words = 0;
	while (str[i])
	{
		if (is_charset(str[i], charset))
			is_word = 0;
		else if (!is_word)
		{
			is_word = 1;
			count_words++;
		}
		i++;
	}
	return (count_words);
}

int	ft_word_len(char *str, char *charset)
{
	int	i;
	int	counter;
	int	charset_counter;

	i = 0;
	counter = 0;
	charset_counter = 0;
	while (str[i])
	{
		if (str[i] && !is_charset(str[i], charset))
		{
			while (str[i] && !is_charset(str[i], charset))
			{
				counter++;
				i++;
			}
			return (counter);
		}
		i++;
	}
	return (counter);
}

void	ft_strcpy(char *str, char *charset, char *array)
{
	int	i;

	i = 0;
	while (str[i] && !is_charset(str[i], charset))
	{
		array[i] = str[i];
		i++;
	}
	array[i] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		next_word;
	int		i;

	i = 0;
	next_word = 0;
	array = (char **)malloc(sizeof(char *) * count_words(str, charset) + 1);
	if (!array)
		return (NULL);
	while (i < count_words(str, charset))
	{
		array[i] = (char *)malloc(sizeof(char) * (ft_word_len(str + next_word,
						charset) + 1));
		if (!array[i])
			return (NULL);
		ft_strcpy(str + next_word, charset, array[i]);
		next_word += ft_word_len(str + next_word, charset);
		while (is_charset(str[next_word], charset))
			next_word++;
		i++;
	}
	return (array);
}

/* #include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	unsigned long int count = count_words(av[1], av[2]);
	char	**result;

	result = ft_split(av[1], av[2]);

	for (size_t i = 0; i < count; i++)
	{
		printf("%s\n", result[i]);
	}
} */