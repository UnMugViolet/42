/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:43:27 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/20 17:13:56 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():  Animal(), _sound("Woof")
{
	this->type = "Dog";
	std::cout << GREEN << "Dog default constructor called" << NEUTRAL << std::endl;
}

Dog::~Dog()
{
	std::cout << RED << "Dog destructor called" << NEUTRAL << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "🐕 Dog sound is: " << this->_sound << std::endl;
}
