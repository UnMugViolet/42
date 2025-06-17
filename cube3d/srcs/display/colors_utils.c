/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:20:21 by pjaguin           #+#    #+#             */
/*   Updated: 2025/06/17 18:22:18 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	encode_rgb(char *red, char *green, char *blue)
{
	return (ft_atoi(red) << 16 | ft_atoi(green) << 8 | ft_atoi(blue));
}
