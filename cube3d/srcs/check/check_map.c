/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:37:44 by yguinio           #+#    #+#             */
/*   Updated: 2025/06/05 15:30:14 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static bool	ft_is_not_already(char orientation, t_check_map *check)
{
	if (orientation == 'N' && !check->n)
		return (check->n = true, true);
	if (orientation == 'S' && !check->s)
		return (check->s = true, true);
	if (orientation == 'E' && !check->e)
		return (check->e = true, true);
	if (orientation == 'W' && !check->w)
		return (check->w = true, true);
	if (orientation == 'C' && !check->c)
		return (check->c = true, true);
	if (orientation == 'F' && !check->f)
		return (check->f = true, true);
	return (false);
}

static bool	check_map_chars(char **map)
{
	int			i;
	int			j;
	t_check_map	check;

	ft_memset(&check, 0, sizeof(t_check_map));
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (!ft_is_charset(map[i][j], " 01NSEW") ||
				(ft_is_charset(map[i][j], "NSEW") &&
					!ft_is_not_already(map[i][j], &check)))
				return (print_err_exit(MAP_CHAR_ERR, NULL, NULL), false);
	}
	return (true);
}

char	**extract_map(char **map_file)
{
	t_point		p;
	char		*temp;
	t_check_map	check;

	ft_memset(&check, 0, sizeof(t_check_map));
	p.y = -1;
	while (map_file[++p.y])
	{
		p.x = -1;
		temp = map_file[p.y];
		if (ft_is_charset(temp[0], "NSEWCF"))
		{
			if (ft_is_not_already(temp[0], &check))
				continue ;
			else
				return (printf("line : %i | %s\n", p.y, temp), NULL);
		}
		while (temp[++p.x])
		{
			if (!ft_is_charset(temp[p.x], "1 "))
				return (print_err_exit(MAP_CHAR_ERR, NULL, NULL), NULL);
			if (temp[p.x] == '1')
				return (ft_str_array_dup(&map_file[p.y]));
		}
	}
	return (print_err_exit(MAP_ERR, NULL, NULL), NULL);
}

bool	check_map(char **map_file)
{
	t_point	p;
	char	**map;
	char	**temp;

	ft_memset(&p, 0, sizeof(t_point));
	map = extract_map(map_file);
	if (!map)
		return (false);
	ft_print_array_str_fd(map, 1);
	if (!check_map_chars(map))
		return (ft_free_array_str(map), false);
	temp = map_borders(map);
	return (ft_free_array_str(map), true);
}

bool	check_map_file(char *map_filename)
{
	char		**map_file;

	map_file = get_map_file(map_filename);
	if (!map_file || !check_textures(map_file) || !check_map(map_file))
		return (ft_free_array_str(map_file), false);
	return (ft_free_array_str(map_file), true);
}
