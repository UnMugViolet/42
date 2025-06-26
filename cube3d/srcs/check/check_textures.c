/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:40:08 by yguinio           #+#    #+#             */
/*   Updated: 2025/06/26 10:20:24 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Checks if the given color respects the RGB format.
 * @param char*rgb_color
 * @return bool
 */
static bool	rgb_format(char *rgb_color)
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	temp = ft_split(rgb_color, ',');
	while (temp[i])
	{
		if (!(0 <= ft_atoi(temp[i]) && ft_atoi(temp[i]) <= 255))
			return (ft_free_array_str(temp), false);
		j = 0;
		while (temp[i][j])
		{
			if (!ft_isdigit(temp[i][j]))
				return (ft_free_array_str(temp), false);
			j++;
		}
		i++;
	}
	if (i != 3)
		return (ft_free_array_str(temp), false);
	return (ft_free_array_str(temp), true);
}

/*
 * Checks it the file contains the two RGB format colors needed for the floor
 * and the ceiling.
 * @param char**file
 * @return bool
 */
bool	check_color(char **file)
{
	int			i;
	char const	*surfaces[2] = {"F", "C"};
	char		*rgb_color;

	i = 0;
	while (i < 2)
	{
		rgb_color = get_surface_value(file, surfaces[i]);
		if (!rgb_color || !rgb_format(rgb_color))
		{
			ft_free(rgb_color);
			return (false);
		}
		ft_free(rgb_color);
		i++;
	}
	return (true);
}

/*
 * Checks if the map file contains all 4 needed textures for each orientation
 * and they are readable files.
 * @param char**file
 * @return bool
 */
bool	check_textures(char **file)
{
	int			i;
	char const	*orientations[] = {"NO", "SO", "EA", "WE"};
	char		*path;

	i = 0;
	while (i < 4)
	{
		path = get_surface_value(file, orientations[i]);
		if (!path || access(path, O_RDONLY) < 0)
		{
			ft_free(path);
			return (print_err_exit(TEXT_ERR, NULL, NULL), false);
		}
		ft_free(path);
		i++;
	}
	if (!check_color(file))
		return (print_err_exit(COLOR_ERR, NULL, NULL), false);
	return (true);
}
