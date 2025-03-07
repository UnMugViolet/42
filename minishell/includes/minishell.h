/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:39:19 by pjaguin           #+#    #+#             */
/*   Updated: 2025/03/07 18:06:15 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "dictionnary.h"
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

typedef struct sigaction	t_sigaction;

typedef struct s_data
{
	int						in_fd;
	int						out_fd;
	int						pipefd[2];
	int						cmd_count;
	char					*prompt;
	char					**env;
	char					**paths;
	char					**current_cmd;
}							t_data;

int							ft_key_press(int keycode);
void						ft_handle_input(void);
void						ft_setup_signals(void);

// Parsing of the data given by the user
void						ft_parse_prompt(char *prompt, t_data *data);

// Init all the stuctures
void						ft_init_data(t_data *data, char *prompt, char **env);

// Handle the execution of the program
void						ft_exec_prompt(char *str);

// Exit management
void						ft_exit_clean(char *prompt, t_data *data);

#endif
