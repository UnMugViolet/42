/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:47:19 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/08 11:22:36 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	echo(int file)
{
	char	character;

	while (read(file, &character, 1))
		write(1, &character, 1);
	close(file);
}

int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n", 2);
		return (1);
	}
	else if (argc == 1)
	{
		ft_putstr("File name missing.\n", 2);
		return (1);
	}
	if (open(argv[1], O_RDONLY) < 0)
	{
		ft_putstr("Cannot read file.\n", 2);
		return (1);
	}
	echo(open(argv[1], O_RDONLY));
	return (0);
}
