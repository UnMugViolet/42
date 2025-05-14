/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:20:16 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/06 17:06:05 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>
#include <cctype>
#include <string.h>

std::string int_to_str(int number)
{
	std::stringstream ss;
	ss << number;
	return (ss.str());
}

bool str_is_digit(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

std::string format_string(std::string str, int len)
{
	if (str.length() > static_cast<std::string::size_type>(len))
		str = str.substr(0, len - 1) + ".";
	else
		str.insert(0, len - str.length(), ' ');
	return (str);
}

std::string  format_field(std::string field, char c)
{
	for (size_t i = 0; i < field.size(); i++)
	{
		field[i] = tolower(field[i]);
		if (field[i] == c)
			field[i] = ' ';
	}
	field[0] = toupper(field[0]);
	return (field);
}
