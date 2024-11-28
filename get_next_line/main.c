/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:01:42 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/27 15:41:42 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	int fd = open(av[1], O_RDONLY);

	for (int i = 0; i < 2; i++)
	{
		char *line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
}
