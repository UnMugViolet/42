/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:42:22 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/16 11:07:35 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}


Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

// Conversion functions
Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(nbr * (1 << this->_fractionalBits));
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = nbr << this->_fractionalBits;
}

int Fixed::toInt(void) const
{
	return this->_fixedPointValue >> this->_fractionalBits;
}

float Fixed::toFloat(void) const
{
	return (float)this->_fixedPointValue / (1 << this->_fractionalBits);
}

// Getters and Setters
int Fixed::getRawBits(void) const
{
	return this->_fixedPointValue;
}

Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPointValue = other.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return o;
}
