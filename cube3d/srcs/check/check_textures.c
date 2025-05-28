/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:40:08 by yguinio           #+#    #+#             */
/*   Updated: 2025/05/28 15:22:04 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	check_color(char **file)
{	
	int			i;
	char		*surfaces[] = {"F", "C"};
	char 		*rgb_color;
	
	i = 0;
	while (i < 2)
	{
		rgb_color = get_surface_value(file, surfaces[i]);
		if (!rgb_color)
		{
			ft_free(rgb_color);
			return false;
		}
		ft_free(rgb_color);
		i++;
	}
	return (true);
}

bool	check_textures(char **file)
{
	int			i;
	char		*orientations[] = {"NO", "SO", "EA", "WE"};
	char 		*path;
	
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
	return (true);
}
