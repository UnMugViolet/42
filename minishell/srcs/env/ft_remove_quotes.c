/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:26:46 by fureimu           #+#    #+#             */
/*   Updated: 2025/04/08 10:30:38 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_count_quotes(const char *str, int *squote, int *dquote)
{
	bool	in_qt[2];

	in_qt[0] = false;
	in_qt[1] = false;
	*squote = 0;
	*dquote = 0;
	while (*str)
	{
		if (*str == '\'' && !in_qt[1])
		{
			(*squote)++;
			in_qt[0] = !in_qt[0];
		}
		if (*str == '\"' && !in_qt[0])
		{
			(*dquote)++;
			in_qt[1] = !in_qt[1];
		}
		str++;
	}
}

static void	ft_need_more_lines(char **dest, char **str)
{
	**dest = **str;
	*dest += 1;
	*str += 1;
}

static void	ft_more_lines(char **str, bool *in_qt, int *n)
{
	*in_qt = !(*in_qt);
	*n -= 1;
	*str += 1;
}

/*
	Removes the quotes in the string `str` if they are paired with another one
	of the same type (single `'` or double `'`).
	@param char*str
	@return void
*/
void	ft_remove_quotes_if_pair(char *str)
{
	char	*dest;
	int		n[2];
	bool	in_qt[2];

	if (!str)
		return ;
	ft_count_quotes(str, &n[0], &n[1]);
	in_qt[0] = false;
	in_qt[1] = false;
	dest = str;
	while (*str)
	{
		if (*str == '\'' && !in_qt[1] && (in_qt[0] || (!in_qt[0] && n[0] > 1)))
		{
			ft_more_lines(&str, &in_qt[0], &n[0]);
			continue ;
		}
		if (*str == '\"' && !in_qt[0] && (in_qt[1] || (!in_qt[1] && n[1] > 1)))
		{
			ft_more_lines(&str, &in_qt[1], &n[1]);
			continue ;
		}
		ft_need_more_lines(&dest, &str);
	}
	*dest = '\0';
}
