/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:23:24 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/22 15:37:34 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{	
}

Ice::Ice(Ice const &other): AMateria(other)
{
	*this = other;
}

Ice::~Ice()
{
}

Ice &Ice::operator=(Ice const &other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

Ice *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
