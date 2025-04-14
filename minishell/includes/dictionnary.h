/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionnary.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:30:32 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/04/11 17:52:06 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONNARY_H
# define DICTIONNARY_H

/*--------------------------------ERRORS--------------------------------------*/

# define ERR_OUT STDERR_FILENO

# define ERR_QUOTE "Missing closing quote.\n"
# define ERR_DUP "minishell: Error in dup2\n"
# define ERR_EXIT_SYNTAX "minishell: exit: numeric argument required\n"
# define ERR_EXIT_TOO_MANY "minishell: exit: too many arguments\n"
# define ERR_EXPORT_SYNTAX "minishell: export: `%s`: not a valid identifier\n"
# define STDRD_ERR "minishell: %s: %s\n"
# define STDRD_ERR_SINGLE "minishell: %s\n"
# define MALLOC_ERROR "Error: malloc failed, cannot allocate memory.\n"
# define CMD_NOT_FOUND "minishell: %s: command not found\n"
# define PERM_DENIED "minishell: %s: permission denied\n"
# define STX_ERR "minishell: syntax error near unexpected token '%s'\n"
# define STX_ERR_N "minishell: syntax error near unexpected token '\\n'\n"
# define EOF_HD_ERR "\nminishell: warning: here-document at line 1 delimited by \
end-of-file (wanted `%s')\n"
# define STX_FLM_ERR "miniflemme: syntax error near unexpected token '%s'\n"

/*--------------------------------COLORS--------------------------------------*/

# define CYN "\x1B[36m"
# define BLK "\x1B[0m"

# define BOLD "\033[1m"
# define ITALIC "\033[3m"
# define UNDERLINE "\033[4m"
# define RESET "\033[0m"

/*-------------------------------OPERATORS------------------------------------*/

# define ENPTY 0
# define WORD 1
# define PIPE 2
# define DBL_PIPE 3
# define AMPERSAND 4
# define DBL_AMPERSAND 5
# define LEFT_BRACKET 6
# define DBL_LEFT_BRACKET 7
# define RIGHT_BRACKET 8
# define DBL_RIGHT_BRACKET 9

/*---------------------------------TOKEN--------------------------------------*/

# define METACHAR "<< >> < > || | && &"

/*------------------------------- DEFAULT-------------------------------------*/

# define DEF_PATH "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
# define BUILTINS "pwd echo cd env export unset exit"
# define DEF_SHLVL "SHLVL=0"
# define DEF_LAST_ARG "_="

#endif
