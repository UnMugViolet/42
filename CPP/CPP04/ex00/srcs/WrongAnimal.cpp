/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:20:46 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 10:50:26 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("Default")
{
	std::cout << GREEN << "WrongAnimal default constructor called" << NEUTRAL << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
	std::cout << GREEN << "WrongAnimal copy constructor called" << NEUTRAL << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal destructor called" << NEUTRAL << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	if (this != &other)
	{
		std::cout << GREEN  << "WrongAnimal Assignation operator called" << NEUTRAL  << std::endl;
		this->type = other.type;
	}
	return *this;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "* Unrecognized WrongAnimal sound *" << std::endl;
}

