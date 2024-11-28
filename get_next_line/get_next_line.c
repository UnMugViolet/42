/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:03:18 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/28 11:35:44 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *main_str)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!main_str[i])
		return (NULL);
	while (main_str[i] && main_str[i] != '\n')
		i++;
	str = ft_calloc(sizeof(char), (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (main_str[i] && main_str[i] != '\n')
	{
		str[i] = main_str[i];
		i++;
	}
	if (main_str[i] == '\n')
	{
		str[i] = main_str[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_get_next_content(char *main_str)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	main_str_len;

	i = 0;
	j = 0;
	main_str_len = ft_strlen(main_str);
	while (main_str[i] && main_str[i] != '\n')
		i++;
	if (!main_str[i])
	{
		free(main_str);
		return (NULL);
	}
	str = ft_calloc(sizeof(char), main_str_len - i + 1);
	if (!str)
		return (NULL);
	while (main_str[++i])
		str[j++] = main_str[i];
	str[j] = 0;
	free(main_str);
	return (str);
}

char	*read_file(int fd, char *main_str)
{
	char	*buff;
	int		count;

	count = 1;
	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr(main_str, '\n') && count != 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == -1)
		{
			if (buff)
				free(buff);
			if (main_str)
				free(main_str);
			return (NULL);
		}
		buff[count] = 0;
		main_str = ft_strjoin(main_str, buff);
	}
	free(buff);
	return (main_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*main_str = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	main_str = read_file(fd, main_str);
	if (!main_str)
		return (NULL);
	line = ft_get_line(main_str);
	main_str = ft_get_next_content(main_str);
	return (line);
}
