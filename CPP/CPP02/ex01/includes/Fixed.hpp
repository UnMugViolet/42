/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:30:05 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/05/16 10:34:50 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(float const nbr);
		Fixed(int const nbr);
		Fixed(const Fixed &other);
		Fixed 	&operator=(Fixed const &other);
		float	toFloat(void) const;
		int		toInt(void) const;
};

#endif
