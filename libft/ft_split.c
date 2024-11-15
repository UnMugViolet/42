/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:43:12 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/15 10:23:03 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *str, char c)
{
	size_t	i;
	int		is_word;
	size_t	words_count;

	i = 0;
	is_word = 0;
	words_count = 0;
	while (str[i])
	{
		if (str[i] == c)
			is_word = 0;
		else if (!is_word)
		{
			is_word = 1;
			words_count++;
		}
		i++;
	}
	return (words_count);
}

int	ft_word_len(const char *str, char c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] && str[i] != c)
		{
			while (str[i] && str[i] != c)
			{
				size++;
				i++;
			}
			return (size);
		}
		i++;
	}
	return (size);
}

char	**ft_split(char const *str, char c)
{
	char	**array;
	size_t	i;
	size_t	words_count;
	size_t	next_word;

	i = 0;
	next_word = 0;
	words_count = count_words(str, c);
	array = (char **)malloc(sizeof(char *) * words_count + 1);
	if (!array)
		return (NULL);
	while (i < words_count)
	{
		array[i] = (char *)malloc(sizeof(char) * ft_word_len(str + next_word, c) + 1);
		if (!array[i])
			return (NULL);
		ft_strlcpy(array[i], (char *)str + next_word, ft_word_len(str + next_word, c));
		next_word += ft_word_len(str + next_word, c);
		while (str[next_word] == c)
			next_word++;
		i++;
	}
	array[i] = 0;
	// free big & small
	return (array);
}
