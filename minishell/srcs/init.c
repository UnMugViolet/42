/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:39:02 by pjaguin           #+#    #+#             */
/*   Updated: 2025/03/07 17:53:10 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_get_paths_from_env(t_data *data, char **env)
{
	int	i;

	i = 0;
	if (!(*env))
	{
		data->paths = ft_split(DEF_PATH, ':');
		return ;
	}
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	data->paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (data->paths[++i])
		data->paths[i] = ft_strjoin_free(data->paths[i], "/");
}

static void ft_default_data(t_data *data, char **env)
{
	data->env = env;
	ft_get_paths_from_env(data, env);
	data->in_fd = STDIN_FILENO;
	data->out_fd = STDOUT_FILENO;
}	

/* Initialize the struct `data` it contains all the main data for the project
@param prompt
@param env
@return void */
void	ft_init_data(t_data *data, char *prompt, char **env)
{
	data->prompt = prompt;
	ft_default_data(data, env);
}
