/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:00:12 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/03/24 17:27:32 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lex_del_content(t_lex *lex)
{
	if (lex)
	{
		if (lex->content)
			free(lex->content);
		lex->type = 0;
		lex->content = ft_strdup("");
	}
}

// TODO: remove for final version debug only
void	ft_print_lex(t_lex *lex)
{
	while (lex)
	{
		if (lex->type)
			printf("type: %zu content: %s\n", lex->type, lex->content);
		lex = lex->next;
	}
	printf("\n");
}

/*
	Returns the content of the last `word` element in the `lex` linked list.
	Returns `NULL` if no word in the `lex` linked list.
	@param t_lex*lex
	@return char *
*/
char	*ft_get_last_word(t_lex *lex)
{
	char	*last;

	last = NULL;
	while (lex)
	{
		if (lex->type == WORD)
			last = lex->content;
		lex = lex->next;
	}
	return (last);
}
