/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:05:36 by yguinio           #+#    #+#             */
/*   Updated: 2025/06/30 18:16:46 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Destroy all textures in the `(t_img)engine.data.textures` array.
 * @param t_engine*engine
 * @return void
 */
void	destroy_textures(t_engine *engine)
{
	int	i;

	i = 0;
	if (engine)
	{
		while (i < 4)
		{
			if (engine->data.map.textures[i].img_ptr)
			{
				mlx_destroy_image(engine->mlx,
					engine->data.map.textures[i].img_ptr);
				engine->data.map.textures[i].img_ptr = NULL;
			}
			i++;
		}
	}
}

/*
 * Stores the XPM file using its `path` into the given `t_img*image` struct
 * @param t_engine*engine
 * @param char*path
 * @param t_img*image
 * @return bool
 */
bool	get_new_image(t_engine *engine, char *path, t_img *image)
{
	if (!engine || !path || !image)
		return (false);
	image->img_ptr = mlx_xpm_file_to_image(engine->mlx, path, &image->w,
			&image->h);
	if (!image->img_ptr)
		return (print_err_exit("Cannot read file : ", path, engine), false);
	image->addr = mlx_get_data_addr(image->img_ptr, &(image->bpp),
			&(image->line_len), &(image->endian));
	return (true);
}

/*
 * Returns the path linked to the given `orientation` in the `file`
 * @param char**file
 * @param char*orientation
 * @return char*
 */
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
	return (print_err_exit(TEXTURE_MISS, NULL, NULL), exit(EXIT_FAILURE), NULL);
}

/*
 * Stores the textures into the `(t_img)engine.data.textures` array
 * @param t_engine*engine
 * @param char*file_path
 * @return bool
 */
bool	get_textures(t_engine *engine, char *file_path)
{
	char const	*orientations[] = {"NO", "SO", "EA", "WE"};
	char		**temp;
	char		*path;
	int			i;

	temp = get_map_file(file_path);
	if (!temp)
		return (false);
	i = 0;
	while (i < 4)
	{
		path = get_surface_value(temp, orientations[i]);
		if (!path || access(path, O_RDONLY) < 0)
			return (ft_free(path), ft_free_array_str(temp),
				print_err_exit(ERR_FILE, NULL, NULL), false);
		get_new_image(engine, path, &engine->data.map.textures[i]);
		ft_free(path);
		i++;
	}
	return (ft_free_array_str(temp), true);
}

bool	get_colors(t_engine *engine, char *file_path)
{
	char const	*surface[] = {"C", "F"};
	char		**temp;
	char		**rgb;
	char		*surface_value;
	int			i;

	temp = get_map_file(file_path);
	if (!temp)
		return (false);
	i = 0;
	while (i < 2)
	{
		surface_value = get_surface_value(temp, surface[i]);
		rgb = ft_split(surface_value, ',');
		engine->data.map.colors[i] = encode_rgb(rgb[0], rgb[1], rgb[2]);
		i++;
		ft_free_array_str(rgb);
		ft_free(surface_value);
	}
	ft_free_array_str(temp);
	return (true);
}
