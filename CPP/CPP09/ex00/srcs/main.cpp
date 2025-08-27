/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:35:29 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/08/27 09:23:05 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream> 
#include <map>

bool	is_txt_well_formatted(char *file)
{
	std::string file_content;
	std::ifstream file_stream(file);

	while (std::getline(file_stream, file_content))
		std::cout << file_content << std::endl;
	if (!file_stream.is_open())
		return true;
	else if (std::string(file).find(".txt") == std::string::npos)
		return true;
	else if (std::string(file).find(".txt") != std::string(file).length() - 4)
		return true;
	return false;
}

int main(int ac, char **av)
{
	std::map<std::string, int> date_value;
 
	if (ac != 2 || is_txt_well_formatted(av[1]))
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
}
