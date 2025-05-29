/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:37:44 by yguinio           #+#    #+#             */
/*   Updated: 2025/05/29 15:48:48 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	**extract_map(char **map_file)
{
	t_point	p;
	char	*temp;

	p.y = -1;
	while (map_file[++p.y])
	{
		p.x = 0;
		temp = map_file[p.y];
		while (temp[p.x] && (temp[p.x] == ' ' || temp[p.x] == '1'))
		{
			if (temp[p.x] == '1')
				return (ft_str_array_dup(&map_file[p.y]));
			p.x++;
		}
	}
	return (NULL);
}

bool	check_map(char **map_file)
{
	t_point	p;
	char	**map;

	ft_memset(&p, 0, sizeof(t_point));
	map = extract_map(map_file);
	if (!map)
		return (false);
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
