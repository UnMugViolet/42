/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:34:57 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/22 12:09:36 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

# include "ICharacter.hpp"
# include "dict.hpp"

class AMateria
{
	protected:
		std::string type;
		
	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(AMateria const &other);

		~AMateria();

		AMateria &operator=(AMateria const &other);

		// Getters
		std::string const & getType() const;
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
