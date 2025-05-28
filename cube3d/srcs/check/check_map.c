/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:37:44 by yguinio           #+#    #+#             */
/*   Updated: 2025/05/28 14:50:28 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	check_map_file(char *map_filename)
{
	char	**map_file;
	
	map_file = get_map_file(map_filename);
	if (!map_file || !check_textures(map_file))
		return (ft_free_array_str(map_file), false);
	return (true);
}
