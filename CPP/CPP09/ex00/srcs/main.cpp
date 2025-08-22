/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:35:29 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/08/22 11:27:13 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>

bool	is_well_formatted(char *av)
{
	std::cout << "Current file: " << av << std::endl;
	return true;
}

int main(int ac, char **av)
{
	if (ac != 2 || is_well_formatted(av[1]))
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	// You can now open and process the file using av[1]
	// Example:
	// std::ifstream file(av[1]);
}
