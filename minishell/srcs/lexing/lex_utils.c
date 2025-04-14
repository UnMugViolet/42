/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:00:12 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/03/21 18:25:37 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lex	*ft_lexnew(size_t type, char *content)
{
	t_lex	*new_element;

	new_element = (t_lex *)ft_calloc(1, sizeof(t_lex));
	if (!new_element)
		return (NULL);
	new_element->content = content;
	new_element->type = type;
	new_element->next = NULL;
	return (new_element);
}

t_lex	*ft_lex_last(t_lex *lex)
{
	if (!lex)
		return (NULL);
	while (lex->next)
		lex = lex->next;
	return (lex);
}

void	ft_lexadd_back(t_lex **lex, t_lex *new)
{
	if (!lex || !new)
		return ;
	if (!*lex)
		*lex = new;
	else
	{
		if (ft_lex_last(*lex))
			ft_lex_last(*lex)->next = new;
	}
}

size_t	ft_lexsize(t_lex *lex)
{
	size_t	i;

	i = 0;
	if (!lex)
		return (i);
	while (lex)
	{
		lex = lex->next;
		i++;
	}
	return (i);
}

void	ft_free_lex(t_lex *lex)
{
	t_lex	*tmp;

	while (lex)
	{
		tmp = lex->next;
		if (lex->content)
			free(lex->content);
		free(lex);
		lex = tmp;
	}
}
