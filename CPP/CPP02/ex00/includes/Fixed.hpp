/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:30:05 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/05/16 10:48:01 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int                 _fixedPointValue;
		static const int    _fractionalBits = 8;
	public:
		Fixed();
		Fixed(Fixed const &other);
		~Fixed();

		int getRawBits(void) const;
		int setRawBits(int const raw);
		Fixed &operator=(Fixed const &other);
};

#endif
