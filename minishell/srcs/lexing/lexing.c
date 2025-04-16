/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:03:08 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/04/03 19:04:38 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Correspondancy tree of the metacharacters
	@param char *str
	@return size_t
 */
static size_t	ft_get_type(char *str)
{
	if (!ft_strncmp(str, "<<", 3))
		return (DBL_LEFT_BRACKET);
	if (!ft_strncmp(str, ">>", 3))
		return (DBL_RIGHT_BRACKET);
	if (!ft_strncmp(str, "<", 2))
		return (LEFT_BRACKET);
	if (!ft_strncmp(str, ">", 2))
		return (RIGHT_BRACKET);
	if (!ft_strncmp(str, "||", 3))
		return (DBL_PIPE);
	if (!ft_strncmp(str, "|", 2))
		return (PIPE);
	if (!ft_strncmp(str, "&&", 3))
		return (DBL_AMPERSAND);
	if (!ft_strncmp(str, "&", 2))
		return (AMPERSAND);
	return (WORD);
}

/*
	That function take the data struct and populate the chained list lex.
	The struct contain the `content` `type` and `next` of the lexeme.
	@param t_data data
	@return void
*/
void	ft_init_prompt_lexing(t_data *data)
{
	int		i;
	size_t	type;
	char	**array;
	t_lex	*new_lex;

	i = 0;
	array = ft_split_strset(data->prompt, data->metachar);
	while (array[i])
	{
		type = ft_get_type(array[i]);
		new_lex = ft_lexnew(type, ft_strdup(array[i]));
		if (!data->lex)
			data->lex = new_lex;
		else
			ft_lexadd_back(&data->lex, new_lex);
		i++;
	}
	ft_free_array_str(array);
	if (ft_get_last_word(data->lex))
		ft_update_env_var(data, "_", ft_get_last_word(data->lex));
	data->lex_size = ft_lexsize(data->lex);
}
