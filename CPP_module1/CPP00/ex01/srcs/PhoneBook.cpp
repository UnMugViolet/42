/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:13:53 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/05 13:55:00 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void create_contact_form()
{
	std::string fields[] = {"first_name", "last_name", "nickname", "phone_number", "darkest_secret"};
	size_t field_count = sizeof(fields)/sizeof(fields[0]);

	for (size_t i = 0; i < field_count ; i++)
	{
		std::cout << "Enter " << fields[i] << ": ";
		std::string input;
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Error: " << fields[i] << " cannot be empty." << std::endl;
			return;
		}
	}
}

void add_contact()
{
	std::cout << "Adding a contact..." << std::endl;
	create_contact_form();
}
