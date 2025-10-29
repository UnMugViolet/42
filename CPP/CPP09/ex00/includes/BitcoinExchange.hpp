#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <limits>

#define MAX_INT std::numeric_limits<int>::max()
#define MIN_INT std::numeric_limits<int>::min()
#define MAX_FLOAT std::numeric_limits<float>::max()
#define MIN_FLOAT -std::numeric_limits<float>::max()
#define MAX_DOUBLE std::numeric_limits<double>::max()
#define MIN_DOUBLE -std::numeric_limits<double>::max()

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

