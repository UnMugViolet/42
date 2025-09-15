/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:35:29 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/08/28 12:06:26 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{ 
	if (ac != 2)
	{
		if (ac > 2)
			std::cerr << RED BOLD << "Error: too many arguments." << NEUTRAL << std::endl;
		else if (ac < 2)
			std::cerr << RED BOLD << "Error: too few arguments." << NEUTRAL << std::endl;
		else if (isInputFileWellFormatted(av[1]))
			std::cerr << RED BOLD << "Error: file not well formatted." << NEUTRAL << std::endl;
		return 1;
	}
	BitcoinExchange btc_data("data/data.csv");
	try {
		btc_data.loadingDatabase();
	} catch (BitcoinExchange::OpenCSVException &e) {
		std::cerr << RED BOLD << e.what() << NEUTRAL << std::endl;
		return 1;
	}
	processInputFile(av[1], btc_data);
	return 0;
}
