/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:13:53 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/05 18:12:23 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

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
	std::cout << "|    Index |First name| Last Name| Nickname |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < this->size; i++)
	{
		this->contacts[i].print_header(i);
	}
	std::cout << "---------------------------------------------" << std::endl;
}

void create_contact_form(Contact *contact)
{
	std::string fields[] = {"first_name", "last_name", "nickname", "phone_number", "darkest_secret"};
	size_t field_count = sizeof(fields)/sizeof(fields[0]);

	for (size_t i = 0; i < field_count ; i++)
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
	create_contact_form(&contact);
	phone_book.create_contact(contact);
}
