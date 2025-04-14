/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_exec_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:24:45 by pjaguin           #+#    #+#             */
/*   Updated: 2025/04/03 17:29:11 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec	*ft_get_next_word(t_exec *exec)
{
	t_exec	*tmp;

	tmp = exec;
	while (tmp)
	{
		if (tmp->type == WORD)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_print_exec(t_exec *exec)
{
	t_exec	*tmp;
	int		i;

	tmp = exec;
	i = 0;
	if (!tmp)
		ft_printf("\nEXEC IS EMPTY\n");
	else
	{
		ft_printf("\nEXEC ARRAY:\n");
		while (tmp)
		{
			ft_printf("Chain nbr: %i\n", ++i);
			ft_print_array_str_fd(tmp->cmd, 1);
			ft_printf("Full Command: %s\n",
				tmp->full_cmd ? tmp->full_cmd : "NULL");
			ft_printf("In fd: %i\n", tmp->in_fd);
			ft_printf("Outfile: %i\n", tmp->out_fd);
			ft_printf("Type: %i\n\n", tmp->type);
			tmp = tmp->next;
		}
	}
}

/*
	Add the `str` string at the end of `array`, if `array` is NULL,
	creates an `array` of 1 string `str`.
	@param char***array
	@param char*str
	@return void
*/
void	ft_add_str_array(char ***array, char *str)
{
	char	**temp;
	int		i;

	i = 0;
	if (!str)
		return ;
	if (!*array)
	{
		*array = (char **)ft_calloc(sizeof(char *), 2);
		if (!*array)
			return ;
		*array[0] = ft_strdup(str);
		return ;
	}
	while (*array[i])
		i++;
	temp = (char **)ft_calloc(sizeof(char *), i + 2);
	if (!temp)
		return ;
	i = -1;
	while (*array[++i])
		temp[i] = ft_strdup(*array[i]);
	temp[i] = ft_strdup(str);
	ft_free_array_str(*array);
	*array = temp;
}
