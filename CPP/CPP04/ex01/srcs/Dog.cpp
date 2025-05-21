/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:43:27 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/21 16:30:39 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal(), _sound("Woof")
{
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << GREEN << "Dog default constructor called" << NEUTRAL << std::endl;
}

Dog::~Dog()
{
	std::cout << RED << "Dog destructor called" << NEUTRAL << std::endl;
	if (this->_brain)
		delete this->_brain;
}

void Dog::makeSound() const
{
	std::cout << "🐕 Dog sound is: " << this->_sound << std::endl;
}

Dog	&Dog::operator=(Dog const &other)
{
	if (this != &other)
	{
		this->_sound = other._sound;
		this->type = other.type;
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain();
	}
	std::cout << GREEN << "Dog deep copy constructor called" << NEUTRAL << std::endl;
	return *this;
}
