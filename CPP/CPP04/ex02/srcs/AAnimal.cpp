/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:20:46 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/22 10:46:37 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(): type("Default")
{
	std::cout << GREEN << "AAnimal default constructor called" << NEUTRAL << std::endl;
}

AAnimal::AAnimal(AAnimal const &other)
{
	*this = other;
	std::cout << GREEN << "AAnimal copy constructor called" << NEUTRAL << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << RED << "AAnimal destructor called" << NEUTRAL << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

void AAnimal::makeSound() const
{
	std::cout << "* Unrecognized aanimal sound *" << std::endl;
}
