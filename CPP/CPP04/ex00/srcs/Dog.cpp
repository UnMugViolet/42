/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:43:27 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/22 11:10:22 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal(), _sound("Woof")
{
	this->type = "Dog";
	std::cout << GREEN << "Dog default constructor called" << NEUTRAL << std::endl;
}

Dog::Dog(Dog const &other): Animal(other)
{
	this->type = other.type;
	this->_sound = other._sound;
	std::cout << GREEN << "Dog copy constructor called" << NEUTRAL << std::endl;
}

Dog::~Dog()
{
	std::cout << RED << "Dog destructor called" << NEUTRAL << std::endl;
}

Dog	&Dog::operator=(Dog const &other)
{
	if (this != &other)
	{
		this->_sound = other._sound;
		this->type = other.type;
	}
	std::cout << GREEN << "Dog assignment operator called" << NEUTRAL << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "🐕 Dog sound is: " << this->_sound << std::endl;
}
