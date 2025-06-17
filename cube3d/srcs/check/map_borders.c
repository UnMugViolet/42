/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:07:09 by yguinio           #+#    #+#             */
/*   Updated: 2025/06/09 11:54:17 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*
 * Returns the lenght of the longest string in the `map` array.
 * @param char**map
 * @return int
 */
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

/*
 * Returns the lenght of the `map` array.
 * @param char**map
 * @return int
 */
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

/*
 * Copy the `original` string to the `dest`, padding the first and the lasts
 * chars with spaces until `len`.
 * @param char*original
 * @param char*dest
 * @param size_t len
 * @return void
 */
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

/*
 * Pads the given `map` with spaces, adding a string at the beginning and the
 * end of the array and on each side of the strings to match the lenght of the
 * longest string.
 * @param char**map
 * @return char**padded_map
 */
char	**pad_map(char **map)
{
	t_point	max;
	t_point	p;
	char	**res;

	max.y = map_rows(map) + 2;
	max.x = map_max_len(map) + 2;
	res = (char **)ft_calloc(sizeof(char *), max.y + 1);
	if (!res)
		return (NULL);
	ft_memset(&p, 0, sizeof(t_point));
	while (p.y < max.y)
	{
		res[p.y] = ft_calloc(sizeof(char), max.x + 2);
		if (!res[p.y])
			return (ft_free_array_str(res), NULL);
		if (p.y == 0 || p.y == max.y)
			ft_copy_with_spaces(NULL, res[p.y], max.x + 1);
		else
			ft_copy_with_spaces(map[p.y - 1], res[p.y], max.x + 1);
		p.y++;
	}
	return (res);
}

/*

	* Checks if the given padded map is closed by trying to acces any char different
 * than `'1'` and `' '`.
 * @param char**map;
 * @param t_point size
 * @param t_point start
 * @return bool
 */
bool	extern_flood_fill(char **map, t_point size, t_point start)
{
	bool	left;
	bool	right;
	bool	up;
	bool	down;

	if (start.y < 0 || start.y >= size.y || start.x < 0 || start.x >= size.x)
		return (true);
	if (map[start.y][start.x] == '1' || map[start.y][start.x] == 'X')
		return (true);
	if (map[start.y][start.x] != ' ')
		return (false);
	map[start.y][start.x] = 'X';
	left = extern_flood_fill(map, size, (t_point){start.x - 1, start.y});
	right = extern_flood_fill(map, size, (t_point){start.x + 1, start.y});
	up = extern_flood_fill(map, size, (t_point){start.x, start.y - 1});
	down = extern_flood_fill(map, size, (t_point){start.x, start.y + 1});
	return (left && right && up && down);
}
