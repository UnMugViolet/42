/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:42:22 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/16 11:55:38 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
}

// Conversion functions
Fixed::Fixed(const float nbr)
{
	this->_fixedPointValue = roundf(nbr * (1 << this->_fractionalBits));
}

Fixed::Fixed(const int nbr)
{
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
	if (this != &other)
		this->_fixedPointValue = other.getRawBits();
	return *this;
}

Fixed Fixed::operator+(Fixed const &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(Fixed const &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(Fixed const &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(Fixed const &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator--(void)
{
	this->_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_fixedPointValue++;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_fixedPointValue--;
	return temp;
}

bool Fixed::operator>(Fixed const &other) const
{
	return this->toFloat() > other.toFloat();
}
bool Fixed::operator<(Fixed const &other) const
{
	return this->toFloat() < other.toFloat();
}

bool Fixed::operator>=(Fixed const &other) const
{
	return this->toFloat() >= other.toFloat();
}

bool Fixed::operator<=(Fixed const &other) const
{
	return this->toFloat() <= other.toFloat();
}

bool Fixed::operator==(Fixed const &other) const
{
	return this->toFloat() == other.toFloat();
}

bool Fixed::operator!=(Fixed const &other) const
{
	return this->toFloat() != other.toFloat();
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a.toFloat() < b.toFloat() ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a.toFloat() > b.toFloat() ? a : b);
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a.toFloat() < b.toFloat() ? a : b);
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a.toFloat() > b.toFloat() ? a : b);
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return o;
}
