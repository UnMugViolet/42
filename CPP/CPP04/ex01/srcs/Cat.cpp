/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:43:27 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/22 11:04:01 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():  Animal(), _sound("Meow")
{
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << GREEN << "Cat default constructor called" << NEUTRAL << std::endl;
}

Cat::Cat(Cat const &other): Animal(other), _sound(other._sound)
{
	if (this != &other)
	{
		this->_sound = other._sound;
		this->type = other.type;
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	std::cout << GREEN << "Cat deep copy constructor called" << NEUTRAL << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << "Cat destructor called" << NEUTRAL << std::endl;
	if (this->_brain)
		delete this->_brain;
}

void Cat::makeSound() const
{
	std::cout << "🐈 Cat sound is: " << this->_sound << std::endl;
}

Cat	&Cat::operator=(Cat const &other)
{
	if (this != &other)
	{
		this->_sound = other._sound;
		this->type = other.type;
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain();
	}
	std::cout << GREEN << "Cat deep copy operator called" << NEUTRAL << std::endl;
	return *this;
}

Brain *Cat::getBrain() const
{
	return this->_brain;
}
