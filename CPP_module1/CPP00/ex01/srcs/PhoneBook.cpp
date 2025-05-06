/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:13:53 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/06 15:52:57 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> 

PhoneBook::PhoneBook()
{
	this->size = 0;
	this->oldest_index = 0;
}

void	PhoneBook::create_contact(const Contact &contact)
{
	if (this->size < 8)
	{
		this->contacts[this->size] = contact;
		this->size++;
	}
	else
	{
		this->contacts[this->oldest_index] = contact;
		this->oldest_index = (this->oldest_index + 1) % 8;
	}
}

void	PhoneBook::print_contact_list()
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First name| Last Name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (size_t i = 0; i < this->size; i++)
		this->contacts[i].print_header(i);
	std::cout << "---------------------------------------------" << std::endl;
}

void PhoneBook::search_contact()
{
    if (this->size == 0)
    {
        std::cout << "PhoneBook is empty. No contacts to search." << std::endl;
        return;
    }
    size_t array_len = this->contacts[0].get_inputs_number();
    std::string formatted_field[array_len];
    const std::string* fields = this->contacts[0].get_input_fields();
    for (size_t i = 0; i < array_len; i++)
        formatted_field[i] = format_field(fields[i], '_');
    this->print_contact_list();
    std::cout << "Enter the index of the contact to view details: ";
    std::string input;
    std::getline(std::cin, input);
    if (std::cin.eof())
    {
        std::cout << "Error: Input stream closed." << std::endl;
        return;
    }
    try
    {
        size_t index = std::atoi(input.c_str());
        if (index >= this->size)
        {
            std::cout << "Error: Invalid index. Please enter a valid index." << std::endl;
            return;
        }
        this->contacts[index].print_contact_single(formatted_field);
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: Invalid input. Please enter a numeric index." << std::endl;
    }
}

void Contact::create_contact_form(Contact *contact)
{
	this->nbr_inputs = sizeof(this->fields)/sizeof(this->fields[0]);
	const std::string* fields = this->get_input_fields(); 
	
	for (size_t i = 0; i < this->nbr_inputs; i++)
	{
		std::cout << "Enter " << fields[i] << ": ";
		std::string input;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "Error: Input stream closed." << std::endl;
			return;
		}
		if (input.empty())
		{
			std::cout << "Error: " << fields[i] << " cannot be empty." << std::endl;
			i--;
			continue;
		}
		contact->set_field(fields[i], input);
	}
}

void add_contact(PhoneBook &phone_book)
{
	Contact contact;
	std::cout << "Adding a contact..." << std::endl;
	contact.create_contact_form(&contact);
	phone_book.create_contact(contact);
}
