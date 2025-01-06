/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bases.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:08:16 by pjaguin           #+#    #+#             */
/*   Updated: 2024/11/22 10:33:00 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASES_H
# define BASES_H

# include "libft.h"

int		ft_atoi_base(char *str, char *base);
char	*ft_itoa_base(int n, char *base);
char	*ft_uitoa_base(unsigned int n, char *base);
char	*ft_ulitoa_base(unsigned long int n, char *base);
size_t	ft_get_in_base(char c, char *str);
size_t	ft_check_base_size(char *str);
size_t	ft_nbrlen_base(size_t nbr, int base_len);

#endif
