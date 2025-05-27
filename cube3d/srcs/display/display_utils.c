/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:05:36 by yguinio           #+#    #+#             */
/*   Updated: 2025/05/27 16:07:30 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	ft_new_file_img(t_engine *cube, char *path, t_img *image)
{
	image->img_ptr = mlx_xpm_file_to_image(cube->mlx, path, image->w, image->h);
	if (!image->img_ptr)
		return (print_err_exit("Cannot read file : ", path, 0), false);
	else
		image->addr = mlx_get_data_addr(image->img_ptr, &(image->bpp),
				&(image->line_len), &(image->endian));
	return (true);
}

char *texture_path(char **file, char *orientation)
{
    int 		i;
    char 		*line;
    size_t const len = ft_strlen(orientation);

    while (*file)
    {
        line = *file;
        if (!strncmp(line, orientation, len) && line[len] == ' ')
        {
            i = 0;
            while (!ft_is_whitespace(line[i]))
                i++;
            while (ft_is_whitespace(line[i]))
                i++;
            return (&line[i]);
        }
        file++;
    }
    return NULL;
}

bool	get_textures(t_engine *cube, char **file)
{
	char *path;

	path = texture_path(file, "NO");
	if (!path)
		path = texture_path(file, "N");
	if (!path)
		return (print_err_exit(NO_ERR, NULL, 0), false);
		
}
