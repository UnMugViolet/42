/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:19:43 by pjaguin           #+#    #+#             */
/*   Updated: 2024/12/05 18:26:55 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*main_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	main_str[fd] = read_file(fd, main_str[fd]);
	if (!main_str[fd])
		return (NULL);
	line = ft_get_line(main_str[fd]);
	main_str[fd] = ft_get_next_content(main_str[fd]);
	return (line);
}
