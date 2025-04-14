/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:24:44 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/03 19:19:01 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_create_exec_conditionaly(t_data *data, char *cmd, size_t type)
{
	char	*path_cmd;
	char	**command;
	char	**cmd_array;

	cmd_array = ft_split_strset(cmd, data->metachar);
	command = ft_split(cmd, ' ');
	if (!cmd_array || !command)
	{
		ft_exit_error(data, MALLOC_ERROR, 2);
		return ;
	}
	path_cmd = ft_get_path_for_cmd(data, command[0]);
	if (!data->exec)
		data->exec = ft_exec_new(cmd_array, path_cmd, type);
	else
		ft_exec_add_back(&data->exec, ft_exec_new(cmd_array, path_cmd, type));
	free(cmd);
	ft_free_array_str(command);
}

void	ft_get_heredocs(t_data *data)
{
	t_lex	*tmp;
	char	*cmd;

	cmd = NULL;
	tmp = data->lex;
	while (tmp)
	{
		if (tmp && tmp->type == DBL_LEFT_BRACKET)
		{
			if (tmp->next && tmp->next->content != NULL)
			{
				cmd = ft_strjoin(tmp->content, " ");
				cmd = ft_strjoin_free(cmd, tmp->next->content);
				ft_lex_del_content(tmp->next);
			}
			else
				cmd = ft_strdup(tmp->content);
			ft_lex_del_content(tmp);
			ft_create_exec_conditionaly(data, cmd, DBL_LEFT_BRACKET);
		}
		tmp = tmp->next;
	}
}

void	ft_get_infiles(t_data *data)
{
	t_lex	*tmp;
	char	*cmd;

	cmd = NULL;
	tmp = data->lex;
	while (tmp)
	{
		if (tmp && tmp->type == PIPE)
			return ;
		if (tmp && tmp->type == LEFT_BRACKET)
		{
			if (tmp->next && tmp->next->content)
			{
				cmd = ft_strjoin(tmp->content, " ");
				cmd = ft_strjoin_free(cmd, tmp->next->content);
				ft_lex_del_content(tmp->next);
			}
			else
				cmd = ft_strdup(tmp->content);
			ft_lex_del_content(tmp);
			ft_create_exec_conditionaly(data, cmd, LEFT_BRACKET);
		}
		tmp = tmp->next;
	}
}

void	ft_get_outfiles(t_data *data)
{
	t_lex	*tmp;
	char	*cmd;

	cmd = NULL;
	tmp = data->lex;
	while (tmp)
	{
		if (tmp && tmp->type == PIPE)
			return ;
		if (tmp && (tmp->type == RIGHT_BRACKET
				|| tmp->type == DBL_RIGHT_BRACKET))
		{
			if (tmp->next && tmp->next->content)
			{
				cmd = ft_strjoin(tmp->content, " ");
				cmd = ft_strjoin_free(cmd, tmp->next->content);
				ft_lex_del_content(tmp->next);
			}
			else
				cmd = ft_strdup(tmp->content);
			ft_create_exec_conditionaly(data, cmd, tmp->type);
			ft_lex_del_content(tmp);
		}
		tmp = tmp->next;
	}
}

void	ft_get_commands(t_data *data)
{
	t_lex	*tmp;
	char	*cmd;

	cmd = NULL;
	tmp = data->lex;
	if (!tmp || !tmp->content)
		return ;
	while (tmp && (tmp->type == WORD || tmp->type == 0))
	{
		if (tmp->content && *tmp->content)
		{
			cmd = ft_strjoin_free(cmd, tmp->content);
			if (tmp->next && (tmp->next->type == WORD || tmp->next->type == 0))
				cmd = ft_strjoin_free(cmd, " ");
		}
		ft_lex_del_content(tmp);
		tmp = tmp->next;
	}
	if (cmd && *cmd)
		ft_create_exec_conditionaly(data, cmd, WORD);
	else
		free(cmd);
}
