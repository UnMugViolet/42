/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:18:37 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/10 11:06:17 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "linked_list.h"
# include "ft_printf.h"
# include <stdbool.h>

typedef struct s_sclistinfo
{
	size_t		total_size;
	size_t		actual_size;
	int			min;
	int			max;
}				t_sclistinfo;

bool			is_correct_input(char **av, int ac);
bool			is_allowed_sign(char c);

t_sclist		**ft_parse(char **av, int ac);
t_sclist		*ft_sclistlast(t_sclist *stack);
bool			ft_issorted(t_sclist *stack_a);
t_sclistinfo	ft_init_sclistinfo(t_sclist *stack_a, t_sclist *stack_b);

void			sa(t_sclist **stack_a);
void			sb(t_sclist **stack_b);
void			ss(t_sclist **stack_a, t_sclist **stack_b);

void			pa(t_sclist **stack_a, t_sclist **stack_b);
void			pb(t_sclist **stack_a, t_sclist **stack_b);

void			ra(t_sclist **stack_a);
void			rb(t_sclist **stack_b);
void			rr(t_sclist **stack_a, t_sclist **stack_b);

void			rra(t_sclist **stack_a);
void			rrb(t_sclist **stack_b);
void			rrr(t_sclist **stack_a, t_sclist **stack_b);

void			sort(t_sclist **stack_a, t_sclist **stack_b);
void			ft_sort_three(t_sclist **stack_a, t_sclistinfo info);
void			ft_sort_big(t_sclist **stack_a, t_sclist **stack_b,
					t_sclistinfo info);

#endif
