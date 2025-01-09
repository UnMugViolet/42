/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:18:37 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/09 11:21:58 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

bool				is_correct_input(char **av, int ac);
bool				is_allowed_sign(char c);

t_stack				**ft_parse(char **av, int ac);
t_stack				*ft_stacklast(t_stack *stack);
bool				ft_issorted(t_stack *stack_a);
size_t				ft_stacksize(t_stack *stack);
void				ft_clean_stack(t_stack **stack);
void				ft_print_stack(t_stack **stack);

void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);

void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);

void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);

void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

#endif
