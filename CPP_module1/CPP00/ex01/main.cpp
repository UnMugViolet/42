/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:31:23 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/06 09:16:21 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Seeder.hpp"

int main(void)
{
	PhoneBook phone_book;
	while (true)
	{
		std::cout << "Enter a command: ";
		std::string command;
		std::getline(std::cin, command);
		if (command == "EXIT" || std::cin.eof())
			break;
		else if (command == "ADD")
			add_contact(phone_book);
		else if (command == "SEED")
			contact_seeder(phone_book); // REMOVE LATER
		else if (command == "PRINT")
			phone_book.print_contact_list();
		else if (command == "SEARCH")
			std::cout << "Searching for a contact..." << std::endl;
		else
			std::cout << "Unknown command." << std::endl;
	}
	return (0);
}
