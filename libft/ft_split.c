/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:43:12 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/15 15:02:15 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(const char *str, char c)
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

size_t	ft_word_len(const char *str, char c)
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

void	free_all(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split(char const *str, char c)
{
	char			**array;
	size_t			i;
	size_t			word_len;
	const size_t	word_count = count_words(str, c);

	i = 0;
	array = (char **)malloc(sizeof(char *) * word_count + 1);
	if (!array)
		return (NULL);
	while (i < word_count)
	{
		while (*str == c)
			str++;
		word_len = ft_word_len(str, c);
		array[i] = (char *)malloc(sizeof(char) * (word_count + 1));
		if (!array[i])
			return (free_all(array), NULL);
		ft_strlcpy(array[i], str, word_len);
		str += word_len;
		i++;
	}
	array[i] = NULL;
	return (array);
}
