/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:20:46 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/21 17:48:40 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Default")
{
	std::cout << GREEN << "Animal default constructor called" << NEUTRAL << std::endl;
}

Animal::Animal(Animal const &other)
{
	*this = other;
	std::cout << GREEN << "Animal copy constructor called" << NEUTRAL << std::endl;
}

Animal::~Animal()
{
	std::cout << RED << "Animal destructor called" << NEUTRAL << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}

Animal &Animal::operator=(Animal const &other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "* Unrecognized animal sound *" << std::endl;
}
