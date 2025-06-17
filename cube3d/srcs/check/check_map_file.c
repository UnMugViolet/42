/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:37:44 by yguinio           #+#    #+#             */
/*   Updated: 2025/06/17 12:02:05 by unmugviolet      ###   ########.fr       */
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

/*
 * Checks if the chars contained in the `map` array are valid and that there is
 * only one orientation for the player.
 */
static bool	check_map_chars(char **map)
{
	int			i;
	int			j;
	size_t		has_spawn;
	t_check_map	check;

	ft_memset(&check, 0, sizeof(t_check_map));
	i = -1;
	has_spawn = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][++j])
		{
			if (ft_is_charset(map[i][j], "NSEW"))
				has_spawn = true;
			if (!ft_is_charset(map[i][j], " 01NSEW"))
				return (print_err_exit(MAP_CHAR_ERR, NULL, NULL), false);
			if (ft_is_charset(map[i][j], "NSEW")
				&& !only_one_orientation(map[i][j], &check))
				return (print_err_exit(MAP_DOUBLE_ERR, NULL, NULL), false);
		}
	}
	if (!has_spawn)
		return (print_err_exit(MAP_SPAWN_ERROR, NULL, NULL), false);
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
	char	**map_file;

	map_file = get_map_file(map_filename);
	if (!map_file || !check_textures(map_file) || !check_map(map_file))
		return (ft_free_array_str(map_file), false);
	return (ft_free_array_str(map_file), true);
}
