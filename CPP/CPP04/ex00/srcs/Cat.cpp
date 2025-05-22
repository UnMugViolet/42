/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:43:27 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/22 11:10:46 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal(), _sound("Meow")
{
	this->type = "Cat";
	std::cout << GREEN << "Cat default constructor called" << NEUTRAL << std::endl;
}

Cat::Cat(Cat const &other): Animal(other)
{
	this->type = other.type;
	this->_sound = other._sound;
	std::cout << GREEN << "Cat copy constructor called" << NEUTRAL << std::endl;
}

Cat	&Cat::operator=(Cat const &other)
{
	if (this != &other)
	{
		this->_sound = other._sound;
		this->type = other.type;
	}
	std::cout << GREEN << "Cat assignment operator called" << NEUTRAL << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << RED << "Cat destructor called" << NEUTRAL << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "🐈 Cat sound is: " << this->_sound << std::endl;
}
