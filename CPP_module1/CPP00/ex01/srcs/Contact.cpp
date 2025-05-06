/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:33:04 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/06 09:23:09 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

Contact::Contact() {}

void	Contact::set_field(std::string field, std::string value)
{
	if (field == "first_name")
		this->first_name = value;
	else if (field == "last_name")
		this->last_name = value;
	else if (field == "nickname")
		this->nickname = value;
	else if (field == "phone_number")
		this->phone_number = value;
	else if (field == "darkest_secret")
		this->darkest_secret = value;
	else
		std::cerr << "Error: Unknown field '" << field << "'" << std::endl;
}

std::string format_string(std::string str)
{
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	else
		str.insert(0, 10 - str.length(), ' ');
	return str;
}

void	Contact::print_header(int index)
{
	std::cout	<< "|" << format_string(int_to_str(index))
				<< "|" << format_string(this->first_name)
				<< "|" << format_string(this->last_name) 
				<< "|" << format_string(this->nickname)
				<< "|" << std::endl;
}

void	Contact::print_contact(int index)
{
	std::cout	<< "Index [" << int_to_str(index) << "]:" << std::endl
				<< "First Name: " << this->first_name << std::endl
				<< "Last Name: " << this->last_name << std::endl
				<< "Nickname: " << this->nickname << std::endl;
}
