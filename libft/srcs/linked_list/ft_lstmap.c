/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:26:30 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/18 15:45:00 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static	void	free_all_list(t_list *new_list, void (*del)(void *))
{
	t_list	*temp;

	while (new_list->next)
	{
		temp = new_list->next;
		del(new_list->content);
		free(new_list);
		new_list = temp;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;

	new_list = NULL;
	while (lst)
	{
		new_element = ft_lstnew((*f)(lst->content));
		if (!new_element)
			free_all_list(new_list, *del);
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	return (new_list);
}
