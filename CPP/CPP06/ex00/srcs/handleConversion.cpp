/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:27:07 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/07/25 17:05:27 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void printSpecial(const std::string &input)
{
	if (input == "nan" || input == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << "nan" << "f" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
	else if (input == "+inf" || input == "+inff" || input == "inff" || input == "inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << "inf" << "f" << std::endl;
		std::cout << "double: " << "inf" << std::endl;
	}
	else if (input == "-inf" || input == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << "-inf" << "f" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
	}
	else	
	{
		std::cerr << RED << BOLD << "Unknown special value." << NEUTRAL << std::endl;
		exit(EXIT_FAILURE);
	}
}

void printCharConversion(const std::string &input, size_t len)
{
	char c = input[0];

	if (len == 1)
		c = input[0];
	else
		c = input[1];
	if (isprint(c))
	{
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;
}

void	printIntConversion(const std::string &input)
{
	double nbr = std::atof(input.c_str());

	std::cout << "char: ";
	if (nbr < 0 || nbr > 127)
		std::cout << "impossible" << std::endl;
	else if (isprint(static_cast<int>(nbr)))
		std::cout << "'" << static_cast<char>(nbr) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (nbr < MIN_INT || nbr > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(nbr) << std::endl;
	std::cout << "float: ";
	if (nbr < MIN_FLOAT || nbr > MAX_FLOAT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(nbr) << "f" << std::endl;
	std::cout << "double: ";
	if (nbr < MIN_DOUBLE || nbr > MAX_DOUBLE)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<double>(nbr) << std::endl;
}

void	printFloatConversion(const std::string &input)
{
	float f = std::atof(input.c_str());

	std::cout << "char: ";
	if (f < 0 || f > 127)
		std::cout << "impossible" << std::endl;
	else if (isprint(static_cast<int>(f)))
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (static_cast<long>(f) < MIN_INT || static_cast<long>(f) > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;
	std::cout << "float: ";
	if (f < MIN_FLOAT || f > MAX_FLOAT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(f) << "f" << std::endl;
}

void	printDoubleConversion(const std::string &input)
{
	double		d = std::atof(input.c_str());

	std::cout << "char: ";
	if (d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(d))
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		else 
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (d < MIN_INT || d > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
	std::cout << "float: ";
	if (d < MIN_FLOAT || d > MAX_FLOAT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: ";
	if (d < MIN_DOUBLE || d > MAX_DOUBLE)
		std::cout << "impossible" << std::endl;
	else
		std::cout << d << std::endl;
}
