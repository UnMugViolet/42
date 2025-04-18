/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:01:49 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/18 11:47:26 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philo.h"
# include <stdbool.h>
# include <stddef.h>

/* ----------------------------------LIBFT---------------------------------- */

void	ft_putstr_fd(char *str, int fd);
int		ft_isdigit(int c);
int		ft_is_whitespace(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);

/* ----------------------------------UTILS---------------------------------- */

void	print_usage(void);
void	print_message(t_philo *philo, char *msg);
size_t	ft_get_time(void);
int		ft_usleep(size_t ms);
void	ft_destroy_all(t_prog *program, pthread_mutex_t *forks, char *str);

/* ----------------------------------CHECKS---------------------------------- */
bool	ft_is_valid_args(int ac, char **av);

#endif
