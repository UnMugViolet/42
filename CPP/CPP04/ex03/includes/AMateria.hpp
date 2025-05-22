/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:34:57 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/22 16:04:04 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string type;

	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(AMateria const &other);

		virtual ~AMateria();

		AMateria &operator=(AMateria const &other);
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);

		// Getters
		std::string const &getType() const;
};

#endif
