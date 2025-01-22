/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:25:15 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/01/22 18:16:31 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

void	ft_checker_error(t_sclist **a, t_sclist **b)
{
	if (a)
		ft_sclst_clean(a);
	else if (b && *b)
		ft_sclst_clean(b);
	else if (b && !*b)
		free(b);
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

static char	*ft_resolve(char *cmd, t_sclist **a, t_sclist **b)
{
	if (!ft_strncmp(cmd, "pb\n", 3))
		pb(a, b, 1);
	else if (!ft_strncmp(cmd, "pa\n", 3))
		pa(a, b, 1);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		sb(b, 1);
	else if (!ft_strncmp(cmd, "sa\n", 3))
		sa(a, 1);
	else if (!ft_strncmp(cmd, "ss\n", 3))
		ss(a, b, 1);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		ra(a, 1);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		rb(b, 1);
	else if (!ft_strncmp(cmd, "rr\n", 3))
		rr(a, b, 1);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		rra(a, 1);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		rrb(b, 1);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		rrr(a, b, 1);
	else
		ft_checker_error(a, b);
	return (get_next_line(0));
}

static void	checker_result(t_sclist **stack_a, t_sclist **stack_b, char *line)
{
	char	*temp;

	while (line && *line != '\n')
	{
		temp = line;
		line = ft_resolve(line, stack_a, stack_b);
		free(temp);
	}
	if (*stack_b || !ft_issorted(*stack_a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free(line);
}

int	main(int ac, char **av)
{
	char		*cmd;
	t_sclist	**a;
	t_sclist	**b;

	if (!is_correct_input(av, ac) || ac < 2)
		return (-1);
	a = ft_parse(av, ac);
	if (!a)
		return (ft_sclst_clean(a), ft_putstr_fd("Error\n", 2), exit(-1), -1);
	b = ft_calloc(sizeof(t_sclist), 1);
	if (!b)
		return (ft_checker_error(a, b), -1);
	cmd = get_next_line(0);
	if (!cmd && !ft_issorted(*a))
		ft_printf("KO\n");
	else if (!cmd && ft_issorted(*a))
		ft_printf("OK\n");
	else
		checker_result(a, b, cmd);
	ft_sclst_clean(a);
	free(b);
	return (0);
}
