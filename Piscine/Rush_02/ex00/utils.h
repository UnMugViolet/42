/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:30:27 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/14 18:16:06 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct dict
{
	int			nbr;
	char		*val;
}				t_dict;

int				ft_strlen(char *str);
void			ft_print(unsigned int output, char *str, unsigned int newline);
unsigned long	ft_atoi(char *str);
char			*ft_strdup(char *str);
void			ft_process_number(int n, t_dict *tab);
t_dict			*get_dict(char *file);
void			ft_putstr(char *str);
t_dict			*get_dict(char *file);
void			ft_print_val(int n, t_dict *tab, int *first);

#endif
