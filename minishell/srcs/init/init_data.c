/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:24:34 by fureimu           #+#    #+#             */
/*   Updated: 2025/04/11 16:11:25 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_current_dir(t_data *data)
{
	char	*colored_prompt;
	char	*tmp;

	if (data->curr_dir)
		free(data->curr_dir);
	data->curr_dir = getcwd(NULL, 0);
	if (!data->curr_dir)
	{
		data->curr_dir = ft_strdup("(*_*)");
		return ;
	}
	tmp = ft_strdup(ft_strrchr(data->curr_dir, '/') + 1);
	if (tmp)
	{
		if (data->curr_dir)
			free(data->curr_dir);
		data->curr_dir = tmp;
	}
	colored_prompt = ft_strjoin(CYN BOLD ITALIC UNDERLINE, data->curr_dir);
	free(data->curr_dir);
	data->curr_dir = ft_strjoin_free(colored_prompt, ">" RESET);
	data->curr_dir = ft_strjoin_free(data->curr_dir, " " BLK);
}

/*
	Increment the value of the `SHLVL` variable in the `env` array
	@param t_data*data
	@return void
*/
static void	ft_inc_shell_lvl(t_data *data)
{
	int		i;
	char	*new_value;

	i = -1;
	while (data->env[++i])
		if (!ft_strncmp(data->env[i], "SHLVL=", 6))
			break ;
	if (!data->env[i])
		return ;
	new_value = ft_itoa(ft_atoi(data->env[i] + 6) + 1);
	if (!new_value)
		new_value = ft_strdup("1");
	free(data->env[i]);
	data->env[i] = ft_strjoin("SHLVL=", new_value);
	free(new_value);
}

/*
	Sets the default values of the `env` array in the `data` struct
	@param t_data*data
	@return void
*/
static void	ft_default_env(t_data *data)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	data->env = (char **)ft_calloc(sizeof(char *), 4);
	data->env[0] = ft_strjoin("PWD=", cwd);
	data->env[1] = ft_strdup(DEF_SHLVL);
	data->env[2] = ft_strdup(DEF_LAST_ARG);
	free(cwd);
}

/*
	Initialize the `data` struct.
	@param t_data*data
	@param char**env
	@return void
*/
void	ft_init_data_struct(t_data *data, char **env)
{
	data->env = ft_str_array_dup(env);
	if (!data->env)
		ft_default_env(data);
	ft_inc_shell_lvl(data);
	data->paths = ft_get_path_from_env(data, true);
	data->prompt = NULL;
	data->curr_dir = NULL;
	data->lex = NULL;
	data->exec = NULL;
	data->pipe_fd[0] = -1;
	data->pipe_fd[1] = -1;
	data->og_stdin = dup(STDIN_FILENO);
	data->og_stdout = dup(STDOUT_FILENO);
	data->pid_count = 0;
	data->metachar = ft_split(METACHAR, ' ');
	data->last_exit_value = ft_strdup("0");
	ft_get_current_dir(data);
}
