/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:31:56 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/10 15:34:49 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_rotation_motion(t_sclist *stack, t_sclist *target,
		t_sclistinfo info, char c)
{
	size_t	count;

	count = 0;
	while (stack != target)
	{
		stack = stack->next;
		count++;
	}
	if (c == 'a')
	{
		if (count < ft_sclst_size(stack) / 2)
			info.motion_a = 1;
		if (count > ft_sclst_size(stack) / 2)
			info.motion_a = -1;
		if (count == 0)
			info.motion_a = 0;
		return ;
	}
	if (count < ft_sclst_size(stack) / 2)
		info.motion_b = 1;
	if (count > ft_sclst_size(stack) / 2)
		info.motion_b = -1;
	else
		info.motion_b = 0;
}

int	ft_get_final_motion(t_sclist *stack_a, t_sclist *target_a,
		t_sclist *stack_b, t_sclist *target_b)
{
	size_t	count;

	count = 0;
	while (stack_a != target_a)
	{
		stack_a = stack_a->next;
		count++;
	}
	while (stack_b != target_b)
	{
		stack_b = stack_b->next;
		count++;
	}
	if (count <= (ft_sclst_size(stack_a)) + (ft_sclst_size(stack_b)) / 2)
		return (1);
	return (-1);
}

t_sclist	*ft_sclst_find_address(t_sclist *stack, int value)
{
	t_sclist	*temp;

	temp = stack;
	while (stack->next != temp)
	{
		if (stack->value == value)
			return (stack);
		stack = stack->next;
	}
	if (stack->value == value)
		return (stack);
	return (NULL);
}

int	ft_sclst_find_index(t_sclist *stack, int value)
{
	int			index;
	t_sclist	*temp;

	index = 0;
	temp = stack;
	while (stack->next != temp)
	{
		if (stack->value == value)
			return (index);
		stack = stack->next;
		index++;
	}
	if (stack->value == value)
		return (index);
	return (-1);
}

bool	ft_issorted(t_sclist *stack_a)
{
	t_sclist	*begin;

	begin = stack_a;
	while (stack_a->next != begin)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

t_sclistinfo	ft_init_sclistinfo(t_sclist *stack_a, t_sclist *stack_b)
{
	t_sclistinfo	info;

	(void)stack_b;
	info.total_size = ft_sclst_size(stack_a);
	info.current_size_a = info.total_size;
	info.min = ft_sclst_min(stack_a);
	info.max = ft_sclst_max(stack_a);
	return (info);
}
