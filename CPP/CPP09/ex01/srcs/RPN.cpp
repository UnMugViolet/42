/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:26:17 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/09/16 16:19:19 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(RPN const &other)
{
	if (this != &other)
		*this = other;
}

RPN &RPN::operator=(RPN const &other)
{
	(void)other;
	return *this;
}

float RPN::calculate(std::string input)
{
	std::list<float> list;
	std::istringstream iss(input);
	std::string token;

	while (iss >> token)
	{
		if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
		{
			if (list.size() < 2)
				throw std::runtime_error("Error: Not enough operands");
			float b = list.back();
			list.pop_back();
			float a = list.back();
			list.pop_back();
			float result;

			switch (token[0])
			{
				case '+':
					result = a + b;
					break;
				case '-':
					result = a - b;
					break;
				case '*':
					result = a * b;
					break;
				case '/':
					if (b == 0)
						throw std::runtime_error("Error: Division by zero");
					result = a / b;
					break;
				default:
					throw std::runtime_error("Error: Unknown operator");
			}
			list.push_back(result);
		}
		else
		{
			// Check if token is a valid single digit (0-9)
			if (token.length() != 1 || !isdigit(token[0]))
				throw std::runtime_error("Error: Invalid token");
			list.push_back(static_cast<float>(token[0] - '0'));
		}
	}
	if (list.size() != 1)
		throw std::runtime_error("Error: Invalid expression");
	return list.back();
}
