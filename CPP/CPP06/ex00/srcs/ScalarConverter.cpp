/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:51:52 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/16 17:03:06 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void printChar(char c, bool isPossible)
{
	if (isPossible)
		std::cout << "char: impossible" << std::endl;
	else if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;	
}

void displayConversion(const std::string &input, char c, int i, float f, double d)
{
	bool isPossible = true;
	std::cout << GREEN << "Conversion results for input: " << input << NEUTRAL << std::endl; // TODO - Remove later
	if (input == "nan" || input == "+inf" || input == "-inf")
		isPossible = false;
	printChar(c, isPossible);
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(std::string const &input)
{
	if (input.empty())
	{
		std::cerr << RED << BOLD << "Error: Empty input." << NEUTRAL << std::endl;
		return;
	}
	ScalarConverter::displayConversion(input, 'a', 42, 42.2f, 42.2);
}
