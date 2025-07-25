/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:51:52 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/25 15:13:18 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "dict.hpp"
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <limits>
# include <cmath>
class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
	public:
		static void convert(const std::string &input);
};

e_type	getType(std::string const &input, size_t len);
void 	printSpecial(const std::string &input); 
void 	printCharConversion(const std::string &input, size_t len);
void 	printIntConversion(const std::string &input);
void 	printFloatConversion(const std::string &input);
void 	printDoubleConversion(const std::string &input);

#endif
