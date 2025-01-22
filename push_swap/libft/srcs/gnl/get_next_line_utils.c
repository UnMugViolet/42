/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:14:26 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/22 10:56:08 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
