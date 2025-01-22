/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:25:15 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/01/22 12:38:59 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	main(void)
{
	char 	*line = NULL;
	int	fd1 = open("libft/srcs/ft_atoi.c", O_RDONLY);

  line = get_next_line(fd1);
  ft_printf("%s", line);
	while (true)
	{
    line = get_next_line(fd1);
    if (!line)
      break ;
		ft_printf("%s", line);
		free(line);
	}
	close(fd1);
}
