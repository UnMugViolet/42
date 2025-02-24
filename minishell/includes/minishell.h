/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:39:19 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/24 15:13:22 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "ft_printf.h"
# include <X11/X.h>
# include <X11/keysym.h>

# include <signal.h>
# include <termios.h> 
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct sigaction t_sigaction;

int		ft_key_press(int keycode);
void	ft_handle_input();
void	ft_exit_clean(char *prompt);
void	ft_setup_signals();

#endif
