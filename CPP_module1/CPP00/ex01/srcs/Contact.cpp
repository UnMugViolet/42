/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:33:04 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/06 14:48:22 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

Contact::Contact() {}

size_t	Contact::get_inputs_number()
{
	return this->nbr_inputs;
}

const std::string* Contact::get_input_fields()
{
    static const std::string fields[] = {"first_name", "last_name", "nickname", "phone_number", "darkest_secret"};
    return fields;
}

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

void	Contact::print_header(int index)
{
	std::cout	<< "|" << format_string(int_to_str(index), 10)
				<< "|" << format_string(this->first_name, 10)
				<< "|" << format_string(this->last_name, 10) 
				<< "|" << format_string(this->nickname, 10)
				<< "|" << std::endl;
}

void	Contact::print_contact_single(int index,std::string formatted_fields[])
{
	(void)index;
	for (size_t i = 0; i < this->get_inputs_number() ; i++)
		std::cout << "|" << format_string(formatted_fields[i], 25);
	std::cout << std::endl;
	for (size_t i = 0; i < this->get_inputs_number(); i++)
		std::cout << "|" << format_string(this->fields[i], 25);
				
} 
