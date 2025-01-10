/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:18:37 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/10 16:58:30 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include "linked_list.h"
# include <stdbool.h>

typedef struct s_sclistinfo
{
	size_t		total_size;
	size_t		current_size_a;
	int			min;
	int			max;
	int			motion_a;
	int			motion_b;
}				t_sclistinfo;

bool			is_correct_input(char **av, int ac);
bool			is_allowed_sign(char c);

t_sclist		**ft_parse(char **av, int ac);
t_sclist		*ft_sclstlast(t_sclist *stack);
t_sclist		*ft_sclst_find_address(t_sclist *stack, int value);
int				ft_sclst_find_index(t_sclist *stack, int value);
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




int	init_pb(t_sclist **stack_a, t_sclist **stack_b, t_sclistinfo info);

#endif
