/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getType.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:03:27 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/08/22 12:37:41 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isSpecial(const std::string &input)
{
	return (input == "nan" || input == "nanf" || input == "+inf" || input == "inf" || input == "+inff" || input == "inff" || input == "-inf" || input == "-inff");
}

static bool isChar(const std::string &input, size_t len)
{
	if (len == 1 && !std::isdigit(input[0]))
		return true;
	if (len == 3 && input[0] == '\'' && input[2] == '\'')
		return true;
	else
		return false;
}

static bool isInt(const std::string &input, size_t len)
{
	if (len == 0)
		return false;
	if (len == 1 && std::isdigit(input[0]))
		return true;
	if (len > 1)
	{
		size_t start = 0;
		if (input[0] == '-' || input[0] == '+')
		{
			if (!std::isdigit(input[1]))
				return false;
			start = 1;
		}
		else if (!std::isdigit(input[0]))
			return false;
		for (size_t i = start; i < len; ++i)
		{
			if (!std::isdigit(input[i]))
				return false;
		}
		return true;
	}
	return false;
}


static bool	isFloat(const std::string &str, size_t &len, size_t &dot)
{
	for (int j = dot - 1; j >= 0; j--)
	{
		if (!isdigit(str[j]) && j != 0)
			return false;
		if (!isdigit(str[j]) && j == 0 && str[j] != '+' && str[j] != '-')
			return false;
	}
	for (size_t i = dot + 1; i < len; i++)
	{
		if (!isdigit(str[i]) && str[i] != 'f')
			return false;
		if (str[i] == 'f' && i != len - 1)
			return false;
	}
	return true;
}

e_type	getType(std::string const &input, size_t len)
{
	size_t dot = input.find('.');
	size_t f = input.find('f');

	if (dot == std::string::npos)
	{
		if (isSpecial(input))
			return SPECIAL;
		if (isChar(input, len))
			return CHAR;
		if (isInt(input, len))
			return INT;
	}
	if (dot != std::string::npos && f != std::string::npos && f == input.length() - 1)
	{
		if (isFloat(input, len, dot))
			return FLOAT;
	} 
	else if (dot != std::string::npos && f == std::string::npos)
	{
		if (isFloat(input, len, dot))
			return DOUBLE;
	}
	return INVALID;
}
