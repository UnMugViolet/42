/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:53:14 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 15:06:10 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: virtual public AMateria
{
	public:
		Ice();
		Ice(Ice const &other);

		~Ice();

		Ice &operator=(Ice const &other);

		Ice *clone() const;
		void use(ICharacter &target);
};

#endif
