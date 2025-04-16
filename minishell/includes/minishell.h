/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:39:19 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/11 18:05:23 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "dictionnary.h"
# include "ft_fprintf.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>

typedef struct s_exec
{
	char					**cmd;
	char					*full_cmd;
	int						in_fd;
	int						out_fd;
	size_t					type;
	struct s_exec			*next;
	struct s_exec			*prev;
}							t_exec;

typedef struct s_lex
{
	size_t					type;
	char					*content;
	struct s_lex			*next;

}							t_lex;

typedef struct s_data
{
	char					*prompt;
	char					**env;
	char					**paths;
	char					**metachar;
	t_lex					*lex;
	size_t					lex_size;
	int						pipe_fd[2];
	pid_t					pid_list[1024];
	int						pid_count;
	int						in_fd;
	int						out_fd;
	int						og_stdin;
	int						og_stdout;
	char					*curr_dir;
	char					*last_exit_value;
	t_exec					*exec;
}							t_data;

typedef struct sigaction	t_sigaction;

extern volatile int			g_sigint_received;

/* ---------------------------------INIT-------------------------------- */

void						ft_init_data_struct(t_data *data, char **env);

/* -------------------------------SIGNALS------------------------------- */

void						ft_setup_signals(void);

/* ---------------------------------ENV--------------------------------- */

void						ft_replace_env_variable(t_data *data);
char						*ft_get_env_var_name(char *str);
char						*ft_get_associated_env_value(t_data *data,
								char *variable);
void						ft_delete_env_var(t_data *data, char *var);
int							ft_create_env_var(t_data *data, char *str);
void						ft_update_env_var(t_data *data, char *variable,
								char *new_value);
char						*ft_get_env_var_adress(t_data *data,
								char *variable);

/* -------------------------------PARSING------------------------------- */

void						ft_parse_prompt(t_data *data);
void						ft_get_heredocs(t_data *data);
void						ft_get_outfiles(t_data *data);
void						ft_get_pipes(t_data *data);
void						ft_get_infiles(t_data *data);
void						ft_get_commands(t_data *data);
void						ft_create_exec_conditionaly(t_data *data, char *cmd,
								size_t type);

/* --------------------------------LEXING------------------------------- */

void						ft_init_prompt_lexing(t_data *data);

/* --------------------------------UTILS-------------------------------- */

void						ft_get_current_dir(t_data *data);

t_lex						*ft_lexnew(size_t type, char *content);
void						ft_lexadd_back(t_lex **lex, t_lex *new);
size_t						ft_lexsize(t_lex *lex);
void						ft_lex_del_content(t_lex *lex);

t_exec						*ft_exec_new(char **cmd, char *path, size_t type);
t_exec						*ft_get_next_word(t_exec *exec);
void						ft_exec_add_back(t_exec **exec, t_exec *new);

void						ft_remove_quotes_if_pair(char *str);
char						*ft_str_substitute(char *str, t_data *data);
char						*ft_get_last_word(t_lex *lex);
void						ft_add_str_array(char ***array, char *str);

void						ft_update_last_exit_value(t_data *data, int value);

void						ft_dup(t_data *data, int fd, int fd2);

/* --------------------------------CHECKS-------------------------------- */

bool						ft_is_correct_input(char *prompt);
bool						ft_is_closed_quotes(char *prompt);
bool						ft_is_token(char *str, t_data *data);
bool						ft_is_builtin(char *str);
bool						ft_is_env_var(char *str);
bool						ft_is_correct_token(t_lex *lex, char **metachar);
bool						ft_is_metacharset(char *str, char **metacharset);
char						*ft_single_token(t_lex *lex, char **metachar);

/* -------------------------------BUILTINS------------------------------- */

int							ft_exec_parent_builtins(t_data *data, char **cmd);
int							ft_exec_child_builtins(t_data *data, char **cmd);
int							ft_cd(t_data *data, char **cmd);
int							ft_echo(char **cmd);
void						ft_exit(t_data *data, char **cmd);

/* ---------------------------------PATH--------------------------------- */

char						**ft_get_path_from_env(t_data *data,
								bool get_default);
char						*ft_get_path_for_cmd(t_data *data, char *cmd);

/* ---------------------------------EXEC--------------------------------- */

void						ft_execute_prompt(t_data *data);
void						ft_exec_child(t_data *data, t_exec *exec,
								pid_t *pid, int is_pipe);
void						ft_wait_and_update_status(t_data *data);
int							ft_handle_redirection(t_data *data, t_exec *exec);
int							ft_exec_heredoc(t_data *data, t_exec *exec,
								char *limiter);
void						ft_check_print_fd(int fd);

/* --------------------------------ERRORS-------------------------------- */

void						ft_exit_error(t_data *data, char *str, int code);
void						ft_exit_clean(t_data *data, int error_code,
								bool write);
void						ft_close_fds(t_data *data);
void						display_usage(void);

/* ---------------------------------FREE--------------------------------- */

void						ft_free_lex(t_lex *lex);
void						ft_free_exec(t_exec *exec);

/* -------------------------PRINTS TO-DO REMOVE LATER---------------------- */

void						ft_print_lex(t_lex *lex);
void						ft_print_exec(t_exec *exec);

#endif
