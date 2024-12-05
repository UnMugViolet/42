/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:03:38 by pjaguin           #+#    #+#             */
/*   Updated: 2024/12/05 18:26:02 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

char	*get_next_line(int fd);
char	*ft_get_line(char *main_str);
char	*ft_get_next_content(char *main_str);
char	*read_file(int fd, char *main_str);

#endif
