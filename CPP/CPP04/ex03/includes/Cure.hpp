/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:53:14 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/22 16:04:21 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: virtual public AMateria
{
	public:
		Cure();
		Cure(Cure const &other);
		~Cure();

		Cure &operator=(Cure const &other);

		Cure *clone() const;
		void use(ICharacter& target);
};

#endif
