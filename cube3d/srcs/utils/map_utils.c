/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:14:23 by yguinio           #+#    #+#             */
/*   Updated: 2025/06/12 11:27:57 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
			if (is_not_already_checked(map_file[p.y][0], &check))
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
