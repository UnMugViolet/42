/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:57:20 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/09 17:33:28 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	is_valid_input(int ac, char **av, t_engine *engine)
{
	(void)engine;
	if (ac != 2 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
		return (false);
	if (!check_map_file(av[1]))
		return (false);
	return (true);
}

/*
	Returns the map file as a char**.
	Exit if it cannot access the file or if the malloc fails.
	@param char*filename
	@return char**
*/
char	**get_map_file(char *filename)
{
	char	**map;
	char	*file;
	char	*line;
	int		fd;

	file = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (print_err_exit(strerror(errno), filename, NULL), NULL);
	line = get_next_line(fd);
	while (line)
	{
		file = ft_strjoin_free(file, line);
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(file, '\n');
	free(file);
	if (!map)
		print_err_exit("Fatal error : split error", NULL, NULL);
	return (close(fd), map);
}
