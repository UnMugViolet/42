/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:31:23 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/05 12:54:02 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	while (true)
	{
		std::cout << "Enter a command: ";
		std::string command;
		std::getline(std::cin, command);
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			std::cout << "Adding a contact..." << std::endl;
		else if (command == "SEARCH")
			std::cout << "Searching for a contact..." << std::endl;
		else
			std::cout << "Unknown command." << std::endl;
	}
	return (0);
}
