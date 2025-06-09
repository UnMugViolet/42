/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:37:44 by yguinio           #+#    #+#             */
/*   Updated: 2025/06/09 12:08:37 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static bool	ft_map_orientation(char orientation, t_check_map *check)
{
	if (orientation == 'N' && !check->n && !check->s && !check->e && !check->w)
		return (check->n = !check->n, true);
	if (orientation == 'S' && !check->n && !check->s && !check->e && !check->w)
		return (check->s = !check->s, true);
	if (orientation == 'E' && !check->n && !check->s && !check->e && !check->w)
		return (check->e = !check->e, true);
	if (orientation == 'W' && !check->n && !check->s && !check->e && !check->w)
		return (check->w = !check->w, true);
	return (false);
}

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
		{
			if (!ft_is_charset(map[i][j], " 01NSEW"))
				return (print_err_exit(MAP_CHAR_ERR, NULL, NULL), false);
			if (ft_is_charset(map[i][j], "NSEW") &&
				!ft_map_orientation(map[i][j], &check))
				return (print_err_exit(MAP_DOUBLE_ERR, NULL, NULL), false);
		}		
	}
	return (true);
}

/*
* Extracts the map from the file containing the textures and map.
* @param char**map_file
* @return char**extracted_map
*/
char	**extract_map(char **map_file)
{
	t_point		p;
	t_check_map	check;

	ft_memset(&check, 0, sizeof(t_check_map));
	p.y = -1;
	while (map_file[++p.y])
	{
		p.x = -1;
		if (ft_is_charset(map_file[p.y][0], "NSEWCF"))
		{
			if (ft_is_not_already(map_file[p.y][0], &check))
				continue ;
			else
				return (printf("line : %i | %s\n", p.y, map_file[p.y]), NULL);
		}
		while (map_file[p.y][++p.x])
		{
			if (!ft_is_charset(map_file[p.y][p.x], "1 "))
				return (print_err_exit(MAP_CHAR_ERR, NULL, NULL), NULL);
			if (map_file[p.y][p.x] == '1')
				return (pad_map(&map_file[p.y]));
		}
	}
	return (print_err_exit(MAP_ERR, NULL, NULL), NULL);
}

bool	check_map(char **map_file)
{
	char	**map;

	map = extract_map(map_file);
	if (!map)
		return (false);
	ft_print_array_str_fd(map, 1);
	if (!check_map_chars(map))
		return (ft_free_array_str(map), false);
	if (!extern_flood_fill(map, (t_point){map_max_len(map), map_rows(map)},
		(t_point){0, 0}))
		return (print_err_exit(OPEN_MAP_ERR, NULL, NULL),
			ft_free_array_str(map), false);
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
