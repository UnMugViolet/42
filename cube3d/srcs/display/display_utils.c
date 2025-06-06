/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:05:36 by yguinio           #+#    #+#             */
/*   Updated: 2025/05/29 14:59:06 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	destroy_textures(t_engine *engine)
{
	int	i;

	i = 0;
	if (engine)
	{
		while (i < 4)
		{
			if (engine->data.textures[i].img_ptr)
			{
				mlx_destroy_image(engine->mlx,
					engine->data.textures[i].img_ptr);
				engine->data.textures[i].img_ptr = NULL;
			}
			i++;
		}
	}
}

bool	get_new_image(t_engine *engine, char *path, t_img *image)
{
	if (!engine || !path || !image)
		return (false);
	image->img_ptr = mlx_xpm_file_to_image(engine->mlx, path,
			&image->w, &image->h);
	if (!image->img_ptr)
	{
		printf("Failed to load texture: %s\n", path);
		return (print_err_exit("Cannot read file : ", path, 0), false);
	}
	image->addr = mlx_get_data_addr(image->img_ptr, &(image->bpp),
			&(image->line_len), &(image->endian));
	return (true);
}

char	*get_surface_value(char **file, char const *orientation)
{
	size_t			i;
	char			*line;
	size_t const	len = ft_strlen(orientation);

	while (*file)
	{
		line = *file;
		if (!strncmp(line, orientation, len) && line[len] == ' ')
		{
			i = len;
			while (ft_is_whitespace(line[i]))
				i++;
			return (ft_strtrim(&line[i], " \n"));
		}
		if (!strncmp(line, orientation, 1) && line[1] == ' ')
		{
			i = 1;
			while (ft_is_whitespace(line[i]))
				i++;
			return (ft_strtrim(&line[i], " \n"));
		}
		file++;
	}
	return (NULL);
}

bool	get_textures(t_engine *engine, char *file)
{
	char const	*orientations[] = {"NO", "SO", "EA", "WE"};
	char		**temp;
	char		*path;
	int			i;

	temp = get_map_file(file);
	if (!temp)
		return (false);
	i = 0;
	while (i < 4)
	{
		path = get_surface_value(temp, orientations[i]);
		if (!path || access(path, O_RDONLY) < 0)
			return (ft_free(path), ft_free_array_str(temp),
				print_err_exit(TEXT_ERR, NULL, NULL), false);
		get_new_image(engine, path, &engine->data.textures[i]);
		ft_free(path);
		i++;
	}
	return (ft_free_array_str(temp), true);
}
