/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:05:36 by yguinio           #+#    #+#             */
/*   Updated: 2025/05/28 15:10:31 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	destroy_textures(t_engine *cube)
{
	int i;

	i = 0;
	if (cube)
	{
		while (i < 4)
		{
			if (cube->data.textures[i].img_ptr)
			{
				mlx_destroy_image(cube->mlx, cube->data.textures[i].img_ptr);
				cube->data.textures[i].img_ptr = NULL;
			}
			i++;
		}
	}
}

static bool	new_img(t_engine *cube, char *path, t_img *image)
{
	image->img_ptr = mlx_xpm_file_to_image(cube->mlx, path, &image->w, &image->h);
	if (!image->img_ptr)
		return (print_err_exit("Cannot read file : ", path, 0), false);
	else
		image->addr = mlx_get_data_addr(image->img_ptr, &(image->bpp),
				&(image->line_len), &(image->endian));
	return (true);
}

char *get_surface_value(char **file, char *orientation)
{
    size_t 		i;
    char 		*line;
    size_t const len = ft_strlen(orientation);

    while (*file)
    {
        line = *file;
        if (!strncmp(line, orientation, len) && line[len] == ' ')
        {
            i = len;
            while (ft_is_whitespace(line[i]))
                i++;
            return (ft_strtrim(&line[i], " \t\n"));
        }
		if (!strncmp(line, orientation, 1) && line[1] == ' ')
        {
            i = 1;
            while (ft_is_whitespace(line[i]))
                i++;
            return (ft_strtrim(&line[i], " \t\n"));
        }
        file++;
    }
    return (NULL);
}

bool	get_textures(t_engine *cube, char **file)
{
	char *path;

	path = get_surface_value(file, "NO");
	if (!path || !new_img(cube, path, &cube->data.textures[0]))
		return (destroy_textures(cube), free(path), false);
	free(path);
	path = get_surface_value(file, "SO");
	if (!path || !new_img(cube, path, &cube->data.textures[1]))
		return (destroy_textures(cube), free(path), false);
	free(path);
	path = get_surface_value(file, "EA");
	if (!path || !new_img(cube, path, &cube->data.textures[2]))
		return (destroy_textures(cube), free(path), false);
	free(path);
	path = get_surface_value(file, "WE");
	if (!path || !new_img(cube, path, &cube->data.textures[3]))
		return (destroy_textures(cube), free(path), false);
	free(path);
	return (true);
}
