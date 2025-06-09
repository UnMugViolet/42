/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:37:44 by yguinio           #+#    #+#             */
/*   Updated: 2025/06/09 12:46:54 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static bool	only_one_orientation(char orientation, t_check_map *check)
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

static bool	is_not_already_checked(char orientation, t_check_map *check)
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

/*
* Checks if the chars contained in the `map` array are valid and that there is
* only one orientation for the player.

*/
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
				!only_one_orientation(map[i][j], &check))
				return (print_err_exit(MAP_DOUBLE_ERR, NULL, NULL), false);
		}
	}
	return (true);
}

/*
* Checks the map file, 4 textures, 2 RGB colors, and the validity of the map
* @param char**map_file
* @return bool
*/
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
