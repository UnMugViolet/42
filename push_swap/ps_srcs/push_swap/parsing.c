/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:06:28 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/05 11:02:00 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sclist	**ft_parse(char **av, int ac)
{
	int			i;
	t_sclist	**stack_a;
	t_sclist	*curr_stack;

	i = 0;
	stack_a = (t_sclist **)ft_calloc(sizeof(t_sclist *), 1);
	if (!stack_a)
		return (NULL);
	while (++i < ac)
	{
		curr_stack = ft_sclist_new(ft_atoi(av[i]));
		if (!curr_stack)
			return (ft_sclst_clean(stack_a), NULL);
		ft_sclist_addback(stack_a, curr_stack);
	}
	return (stack_a);
}
