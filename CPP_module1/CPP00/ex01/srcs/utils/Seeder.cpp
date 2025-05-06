/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Seeder.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:01:17 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/06 10:56:05 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>

void create_contact_form_seeded(Contact *contact, const std::string &seeded_input = "")
{
	std::string fields[] = {"first_name", "last_name", "nickname", "phone_number", "darkest_secret"};
	size_t field_count = sizeof(fields)/sizeof(fields[0]);

	std::istringstream input_stream(seeded_input);
	for (size_t i = 0; i < field_count ; i++)
	{
		std::string input;
		if (!std::getline(input_stream, input))
		{
			std::cerr << "Error: Not enough data in seeded input for field " << fields[i] << std::endl;
            return;
		}
		contact->set_field(fields[i], input);
	}
}

void contact_seeder(PhoneBook &phone_book)
{
	std::string first_names[9] = {"John\n", "Jack\n", "Billy\n", "Eliott\n", "Vadim\n", "Colette\n", "Dididier\n", "Lucien\n", "Maxime\n"};
	std::string nickname[9] = {"Johnny\n", "Jacky\n", "Bad boy\n", "Snitch\n", "Vad\n", "Col\n", "DIDIDIDIIDIDID\n", "ludac\n", "Max\n"};
	for (int i = 0; i < 9; i++)
	{
		Contact contact;
		std::string seeded_input = first_names[i] + "Doe\n" + nickname[i] + int_to_str(i + 1) +"0000000000000\nLoves pizza\n";
		create_contact_form_seeded(&contact, seeded_input);
		phone_book.create_contact(contact);		
	}
}
