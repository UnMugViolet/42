/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:51:52 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/25 17:08:11 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string const &input)
{
	size_t len = input.length();
	e_type type = getType(input, len);
	std::cout << std::fixed << std::setprecision(1);
	
	switch (type)
	{
        case INVALID:
            std::cout << "Invalid input" << std::endl;
            break;
        case SPECIAL:
            printSpecial(input);
            break;
		case CHAR:
			printCharConversion(input, len);
			break;
		case INT:
			printIntConversion(input);
			break;
		case FLOAT:
			printFloatConversion(input);
			break;
		case DOUBLE:
			printDoubleConversion(input);
			break;
		default:
			std::cout << "Unknown type" << std::endl;
			exit(EXIT_FAILURE);
	}
}
