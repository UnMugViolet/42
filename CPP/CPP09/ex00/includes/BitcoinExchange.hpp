/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:38:49 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/09/15 10:45:39 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#define GREEN "\033[0;92m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define NEUTRAL "\033[0m"

#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define ITALIC "\033[3m"


class BitcoinExchange
{
	private:
		std::string						_csvPath;
		std::map<std::string, float>	_rateByDate;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string const database_path);
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange &operator=(BitcoinExchange const &other);
		~BitcoinExchange();

		void		loadingDatabase();
		std::string	getCSVPath() const;
		float		getRate(std::string date);

		class OpenCSVException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};


bool	isValidDate(const std::string& date);
bool	isValidValue(const std::string& value);
bool	isInputFileAccessible(char *file);
void	processInputFile(std::string const &file, BitcoinExchange &btc_data);
float	strToFloat(const std::string& str);

