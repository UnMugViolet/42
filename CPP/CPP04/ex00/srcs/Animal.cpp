/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:20:46 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 10:50:43 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Default")
{
	std::cout << GREEN << "Animal default constructor called" << NEUTRAL << std::endl;
}

Animal::Animal(Animal const &other)
{
	std::cout << GREEN << "Animal copy constructor called" << NEUTRAL << std::endl;
	*this = other;
}

Animal::~Animal()
{
	std::cout << RED << "Animal destructor called" << NEUTRAL << std::endl;
}

Animal &Animal::operator=(Animal const &other)
{
	if (this != &other)
	{
		std::cout << GREEN  << "Animal Assignation operator called" << NEUTRAL  << std::endl;
		this->type = other.type;
	}
	return *this;
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "* Unrecognized Animal sound *" << std::endl;
}

