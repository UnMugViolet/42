/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:38:20 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/14 13:32:23 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	char	*name;

	(void)argc;
	name = argv[0];
	write(1, name, ft_strlen(name));
}
