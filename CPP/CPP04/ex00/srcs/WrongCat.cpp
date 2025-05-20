/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:43:27 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/20 17:14:22 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat():  WrongAnimal(), _sound("Meow")
{
	this->type = "WrongCat";
	std::cout << GREEN << "WrongCat default constructor called" << NEUTRAL << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat destructor called" << NEUTRAL << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "🐈 WrongCat sound is: " << this->_sound << std::endl;
}
