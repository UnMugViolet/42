/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:01:42 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/28 12:11:18 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// Classic with and without buffer
// cc -Wall -Wextra -Werror -g3 -D BUFFER_SIZE=15 get_next_line.c get_next_line_utils.c main.c && ./a.out 
// cc -Wall -Wextra -Werror -g3 -D get_next_line.c get_next_line_utils.c main.c && ./a.out 

// Bonuses
// cc -Wall -Wextra -Werror -g3 get_next_line_bonus.c get_next_line_utils_bonus.c main.c && ./a.out

int	main(void)
{
	int		lines_count = 3;
	char 	*line = NULL;
	int	fd1 = open("tests/test.txt", O_RDONLY);
	int	fd2 = open("tests/test1.txtz", O_RDONLY);
	int	fd3 = open("tests/test2.txt", O_RDONLY);

	for (int i = 1; i < lines_count; i++)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
		line = get_next_line(fd2);
		printf("%s", line);
		free(line);
		line = get_next_line(fd3);
		printf("%s", line);
		free(line);
	}


	close(fd1);
	close(fd2);
	close(fd3);
}
