/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:38:20 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/05 13:16:38 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i] != 0)
	{
		i++;
	}
	return (i);
}

int	main(int argc, char** argv)
{
	(void)argc;
	char	*name;

	name = argv[0];
	write(1, name, ft_strlen(name));
}
