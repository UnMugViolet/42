/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:39:19 by pjaguin           #+#    #+#             */
/*   Updated: 2025/03/06 15:29:15 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "ft_printf.h"
# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>

#define CYN "\x1B[36m" 
#define BLK "\x1B[0m"


typedef struct sigaction	t_sigaction;

typedef struct s_data
{
	char	*input;
	char	**env;
} 			t_data;

int							ft_key_press(int keycode);
void						ft_handle_input(void);
void						ft_exit_clean(char *prompt);
void						ft_setup_signals(void);
void						ft_parse_prompt(char *str);
void						ft_exec_prompt(char *str);

#endif
