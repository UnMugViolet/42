/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:05:10 by rxue              #+#    #+#             */
/*   Updated: 2024/07/14 18:26:49 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

/*get all the number - value from dictionary
and store them in the structure dict
fd: file description
O_RDONLY: a flag, read only
open() will return a fd which is an index to an entry in
the process's table of open file descriptors, if return
	-1 means didn't succede*/

char	*ft_getnbr(int fd)
{
	char	*str;
	char	c[1];
	int		i;

	i = 0;
	str = malloc(sizeof(char) * 128);
	if (!str)
		return (0);
	read(fd, c, 1);
	while (c[0] == '\n')
		read(fd, c, 1);
	while (c[0] >= '0' && c[0] <= '9')
	{
		str[i] = c[0];
		i++;
		read(fd, c, 1);
	}
	str[i] = '\0';
	return (str);
}

char	*ft_getval(int fd, char *c)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * 12);
	if (!str)
		return (0);
	while (c[0] != '\n')
	{
		str[i] = c[0];
		i++;
		read(fd, c, 1);
	}
	str[i] = '\0';
	return (str);
}

t_dict	*get_dict(char *file)
{
	int		fd;
	int		i;
	t_dict	*tab;
	char	c[1];

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	tab = malloc(sizeof(t_dict) * 33);
	if (!tab)
		return (0);
	tab[32].val = NULL;
	i = 0;
	while (i < 32)
	{
		tab[i].nbr = ft_atoi(ft_getnbr(fd));
		read(fd, c, 1);
		while (c[0] == ' ' || c[0] == ':')
			read(fd, c, 1);
		tab[i].val = ft_getval(fd, c);
		i++;
	}
	close(fd);
	return (tab);
}

/*#include <stdio.h>

int	main(void)
{
	int		i;
	dict	*d;

	i = 0;
	d = get_dict("numbers.dict");
	while (d[i].val != 0)
	{
		printf("nbr : %d ", d[i].nbr);
		printf("val : %s\n", d[i].val);
		free(d[i].val);
		i++;
	}
	free(d);
	return (0);
}*/
