/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Seeder.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:01:17 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/06 16:16:40 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include "Contact.hpp"

void Contact::create_contact_form_seeded(const std::string &seeded_input = "")
{
	std::istringstream input_stream(seeded_input);
	for (size_t i = 0; i < this->nbr_inputs; i++)
	{
		std::string input;
		if (!std::getline(input_stream, input))
		{
			std::cerr << "Error: Not enough data in seeded input for field " << this->fields[i] << std::endl;
            return;
		}
		this->set_field(this->fields[i], input);
	}
}

void contact_seeder(PhoneBook &phone_book)
{
	std::string first_names[9] = {"John\n", "Jack\n", "Billy\n", "Eliott\n", "Vadim\n", "Colette\n", "Dididier\n", "Lucien\n", "Maxime\n"};
	std::string nickname[9] = {"Johnny\n", "Jacky\n", "Bad boy\n", "Snitch\n", "Vad\n", "Col\n", "DIDIDIDIDIDID\n", "ludac\n", "Max\n"};
	for (int i = 0; i < 9; i++)
	{
		Contact contact;
		std::string seeded_input = first_names[i] + "Doe\n" + nickname[i] + int_to_str(i + 1) +"0000000000000\nLoves pizza\n";
		contact.create_contact_form_seeded(seeded_input);
		phone_book.create_contact(contact);		
	}
}
