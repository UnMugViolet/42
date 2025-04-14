/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boolean_checks2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:39:26 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/09 13:05:24 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_is_metacharset(char *str, char **metacharset)
{
	int	i;

	i = 0;
	while (metacharset[i])
	{
		if (!ft_strncmp(str, metacharset[i], ft_strlen(metacharset[i])))
			return (true);
		i++;
	}
	return (false);
}

static bool	ft_check_token(t_lex *lex, char **metachar)
{
	int	is_charset;
	int	is_charset_next;

	while (lex)
	{
		is_charset_next = 0;
		is_charset = ft_is_metacharset(lex->content, metachar);
		if (lex->type == DBL_PIPE || lex->type == DBL_AMPERSAND
			|| lex->type == AMPERSAND)
			return (ft_fprintf(ERR_OUT, STX_FLM_ERR, lex->content), 1);
		if (lex->type != WORD && lex->next && lex->next->type == lex->type)
			return (ft_fprintf(ERR_OUT, STX_ERR, lex->next->content, 1));
		if (lex->next)
			is_charset_next = ft_is_metacharset(lex->next->content, metachar);
		if (lex->next && (is_charset && lex->type != PIPE) && is_charset_next)
			return (ft_fprintf(ERR_OUT, STX_ERR, lex->next->content, 1));
		lex = lex->next;
	}
	return (0);
}

static bool	ft_is_only_whitespace(char *str)
{
	while (*str)
	{
		if (!ft_is_whitespace(*str))
			return (false);
	}
	return (true);
}

static bool	ft_check_word_after_redir(t_lex *lex)
{
	char	**redir_charset;

	redir_charset = ft_split("<< < >> >", ' ');
	while (lex)
	{
		if (ft_is_metacharset(lex->content, redir_charset) && (!lex->next
				|| ft_is_only_whitespace(lex->next->content)))
			return (ft_free_array_str(redir_charset), ft_fprintf(ERR_OUT,
					STX_ERR_N), 0);
		else if (!ft_strncmp(lex->content, "|", 2) && (!lex->next
				|| ft_is_only_whitespace(lex->next->content)))
			return (ft_free_array_str(redir_charset), ft_fprintf(ERR_OUT,
					STX_ERR, "|"), 0);
		lex = lex->next;
	}
	return (ft_free_array_str(redir_charset), 1);
}

bool	ft_is_correct_token(t_lex *lex, char **metachar)
{
	if (ft_check_token(lex, metachar))
		return (false);
	if (!ft_check_word_after_redir(lex))
		return (false);
	return (true);
}
