/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionnary.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:59:05 by yguinio           #+#    #+#             */
/*   Updated: 2025/06/26 13:48:58 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONNARY_H
# define DICTIONNARY_H

# define TEXT_ERR "Texture error"
# define COLOR_ERR "Color error. RGB format: [<0-255>,<0-255>,<0-255>]"
# define MAP_ERR "Map error"
# define MAP_CHAR_ERR "Map error: wrong map character"
# define MAP_SPAWN_ERROR "Map error: there is no spawn point"
# define MAP_DOUBLE_ERR "Map error: too many orientation characters"
# define OPEN_MAP_ERR "Map error: Map not closed"
# define START_ERR "Map error: No starting point"
# define FILE_ERR "File error: "

# define YELLOW 0xFFFF4C
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define BLACK 0x000000
# define BLUE 0x0000FF

# define WIN_W 2048
# define WIN_H 1080
# define SPEED 0.1
# define ROTATION 0.05
# define SENSITIVITY 0.00125
# define PI 3.14159265358979323846
# define FOV (PI / 3)
# define NUM_RAYS 2048
# define M_PI_2 (PI / 2.0)

# define EPSILON 0.0000000001
#endif
