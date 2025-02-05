/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:18:37 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/05 11:25:46 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include "linked_list.h"

bool		is_correct_input(char **av, int ac);
t_sclist	**ft_parse(char **av, int ac);

t_sclist	*ft_sclst_last(t_sclist *stack);
t_sclist	*ft_sclst_find_address(t_sclist *stack, int value);
int			ft_sclst_find_index(t_sclist *stack, int value);
bool		ft_issorted(t_sclist *stack_a);
bool		ft_issorted_from_min(t_sclist *stack_a);
int			ft_find_value_place_b(t_sclist *stack_b, int to_push);
int			ft_find_value_place_a(t_sclist *stack_a, int to_push);

void		sa(t_sclist **stack_a, int is_quiet);
void		sb(t_sclist **stack_b, int is_quiet);
void		ss(t_sclist **stack_a, t_sclist **stack_b, int is_quiet);

void		pa(t_sclist **stack_a, t_sclist **stack_b, int is_quiet);
void		pb(t_sclist **stack_a, t_sclist **stack_b, int is_quiet);

void		ra(t_sclist **stack_a, int is_quiet);
void		rb(t_sclist **stack_b, int is_quiet);
void		rr(t_sclist **stack_a, t_sclist **stack_b, int is_quiet);

void		rra(t_sclist **stack_a, int is_quiet);
void		rrb(t_sclist **stack_b, int is_quiet);
void		rrr(t_sclist **stack_a, t_sclist **stack_b, int is_quiet);

void		sort(t_sclist **stack_a, t_sclist **stack_b);
void		ft_sort_three(t_sclist **stack_a);
void		ft_sort_big(t_sclist **stack_a, t_sclist **stack_b);

int			ft_case_rarb_ba(t_sclist *a, t_sclist *b, int val);
int			ft_case_rrarrb_ba(t_sclist *a, t_sclist *b, int val);
int			ft_case_rarrb_ba(t_sclist *a, t_sclist *b, int val);
int			ft_case_rrarb_ba(t_sclist *a, t_sclist *b, int val);

int			ft_case_rarb_ab(t_sclist *a, t_sclist *b, int val);
int			ft_case_rrarrb_ab(t_sclist *a, t_sclist *b, int val);
int			ft_case_rrarb_ab(t_sclist *a, t_sclist *b, int val);
int			ft_case_rarrb_ab(t_sclist *a, t_sclist *b, int val);

int			ft_apply_rarb_ba(t_sclist **a, t_sclist **b, int val);
int			ft_apply_rrarrb_ba(t_sclist **a, t_sclist **b, int val);
int			ft_apply_rarrb_ba(t_sclist **a, t_sclist **b, int val);
int			ft_apply_rrarb_ba(t_sclist **a, t_sclist **b, int val);

int			ft_apply_rarb_ab(t_sclist **a, t_sclist **b, int val);
int			ft_apply_rrarrb_ab(t_sclist **a, t_sclist **b, int val);
int			ft_apply_rrarb_ab(t_sclist **a, t_sclist **b, int val);
int			ft_apply_rarrb_ab(t_sclist **a, t_sclist **b, int val);

int			ft_get_cheapest_ab(t_sclist *a, t_sclist *b);
int			ft_get_cheapest_ba(t_sclist *a, t_sclist *b);

#endif
