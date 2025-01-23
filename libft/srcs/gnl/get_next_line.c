/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:19:43 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/22 18:07:36 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*main_str[4096];

	if (fd < 0)
		return (NULL);
	main_str[fd] = read_file(fd, main_str[fd]);
	if (!main_str[fd])
		return (NULL);
	line = ft_get_line(main_str[fd]);
	main_str[fd] = ft_get_next_content(main_str[fd]);
	return (line);
}
