/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_borders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:07:09 by yguinio           #+#    #+#             */
/*   Updated: 2025/06/04 14:24:39 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	map_max_len(char **map)
{
	int	i;
	int	len;
	int	max_len;

	if (!map)
		return (0);
	i = -1;
	max_len = 0;
	while (map[++i])
	{
		len = ft_strlen(map[i]);
		if (max_len < len)
			max_len = len;
	}
	return (max_len);
}

int	map_rows(char **map)
{
	int	i;

	if (!map)
		return (0);
	i = -1;
	while (map[++i])
		;
	return (i);
}

static void	ft_copy_with_spaces(char *original, char *dest, size_t len)
{
	size_t	i;

	if (!dest || !len)
		return ;
	dest[0] = ' ';
	i = 1;
	while (i < len)
	{
		if (original && *original)
		{
			dest[i] = *original;
			original++;
		}
		else
			dest[i] = ' ';
		i++;
	}
	dest[i] = 0;
}

char	**map_borders(char **map)
{
	t_point		max;
	t_point		p;
	char		**res;

	max.y = map_rows(map) + 2;
	max.x = map_max_len(map) + 2;
	res = (char **)ft_calloc(sizeof(char *), max.y + 1);
	if (!res)
		return (NULL);
	ft_memset(&p, 0, sizeof(t_point));
	while (p.y < max.y)
	{
		res[p.y] = ft_calloc(sizeof(char), max.x + 1);
		if (!res[p.y])
			return (ft_free_array_str(res), NULL);
		if (p.y == 0 || p.y == max.y)
			ft_copy_with_spaces(NULL, res[p.y], max.x + 1);
		else
			ft_copy_with_spaces(map[p.y - 1], res[p.y], max.x + 1);
		ft_printf("Pass [%i] : |%s", p.y, res[p.y]);
		write(1, "|\n", 2);
		p.y++;
	}
	return (res);
}
