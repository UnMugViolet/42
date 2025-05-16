/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:14:42 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/16 15:04:51 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(Point const &copy) : _x(copy._x), _y(copy._y)
{
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
}

float Point::getX(void) const
{
	return this->_x.toFloat();
}

float Point::getY(void) const
{
	return this->_y.toFloat();
}

Point::~Point()
{
}

Point	&Point::operator=(Point const &other)
{
	if (this != &other)
	{
		// _x and _y are const, so we cannot assign them
		// this->_x = other._x;
		// this->_y = other._y;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &os, Point const &point)
{
	os << "Point(" << point.getX() << ", " << point.getY() << ")";
	return os;
}
