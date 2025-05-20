/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:43:27 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/20 17:13:31 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():  Animal(), _sound("Meow")
{
	this->type = "Cat";
	std::cout << GREEN << "Cat default constructor called" << NEUTRAL << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << "Cat destructor called" << NEUTRAL << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "🐈 Cat sound is: " << this->_sound << std::endl;
}
