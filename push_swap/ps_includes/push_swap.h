/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:18:37 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/06 14:43:47 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

bool	is_correct_input(char **av, int ac);
bool	is_allowed_sign(char c);

#endif
