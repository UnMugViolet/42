/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:27:00 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/22 15:41:23 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{	
}

Cure::Cure(Cure const &other)
{
	this->type = other.type;
}

Cure::~Cure()
{
}

Cure &Cure::operator=(Cure const &other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cure *Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
