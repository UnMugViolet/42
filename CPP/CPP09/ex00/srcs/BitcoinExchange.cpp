/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:38:46 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/09/15 11:44:18 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): _csvPath("./data/data.csv") {}

BitcoinExchange::BitcoinExchange(std::string const database_path): _csvPath(database_path) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other): _rateByDate(other._rateByDate)
{
	this->_csvPath = other._csvPath;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this != &other)
	{
		this->_csvPath = other._csvPath;
		this->_rateByDate = other._rateByDate;
	}
	return *this;
}

void	BitcoinExchange::loadingDatabase()
{
	std::ifstream	csv_file(this->_csvPath.c_str());
	std::string		line;

	if (!csv_file.is_open())
		throw OpenCSVException();
	this->_rateByDate.clear();
	std::getline(csv_file, line);
	while (std::getline(csv_file, line))
	{
		std::istringstream	lineStream(line);
		std::string			date;
		std::string			value;

		if (!std::getline(lineStream, date, ',') || !std::getline(lineStream, value))
		{
			std::cerr << RED BOLD << "Error: Line not well formatted => " << NEUTRAL << line << std::endl;
			continue ;
		}
		if (!isValidDate(date))
		{
			std::cerr << RED BOLD << "Error: bad date format in database => " << NEUTRAL << date << std::endl;
			continue ;
		}
		else if (!isValidValue(value))
		{
			std::cerr << RED BOLD << "Error: invalid value in database => " << NEUTRAL << value << std::endl;
			continue;
		}
		this->_rateByDate[date] = strToFloat(value);
	}
}

BitcoinExchange::~BitcoinExchange() {}

/* --------------------------GETTERS -------------------------- */

std::string	BitcoinExchange::getCSVPath() const
{
	return this->_csvPath;
}

float	BitcoinExchange::getRate(std::string date)
{
    if (this->_rateByDate.empty())
        return 0;
    std::map<std::string, float>::const_iterator it = this->_rateByDate.lower_bound(date);
	// Exact match found
    if (it != this->_rateByDate.end() && it->first == date)
        return it->second;
    // No exact match, find the closest earlier date
    if (it == this->_rateByDate.begin())
        return 0;
    --it;
    return it->second;
}


/* ---------------------- BOOLEAN CHECKS ----------------------- */

bool	isValidDate(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2)
	{
		bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (isLeapYear ? 29 : 28))
			return false;
	}
	return true;
}

bool	isInputFileAccessible(char *file)
{
	std::string file_content;
	std::ifstream file_stream(file);

	if (!file_stream.is_open())
		return true;
	else if (std::string(file).find(".txt") == std::string::npos)
		return true;
	else if (std::string(file).find(".txt") != std::string(file).length() - 4)
		return true;
	return false;
}

bool	isValidValue(std::string const &value)
{	
	if (value.empty())
		return (false);

	std::stringstream ss(value);
	float val;

	if (!(ss >> val) || !ss.eof() || val < 0)
		return false;
	return true;
}

/* -------------------------- UTILS -------------------------- */

float strToFloat(const std::string& str)
{
	std::stringstream string(str);
	float value;
	if (!(string >> value) || !string.eof())
		return (-1);
	return (value);
}

void	processInputFile(std::string const &file, BitcoinExchange &btc_data)
{
	std::ifstream	input_file(file.c_str());
	std::string		line;
	bool			first_line = true;

	if (!input_file.is_open())
	{
		std::cerr << RED BOLD << "Error: could not open file." << NEUTRAL << std::endl;
		return ;
	}
	while (std::getline(input_file, line))
	{
		if (first_line)
		{
			first_line = false;
			continue ;
		}
		size_t		pipe_pos = line.find('|');
		if ((pipe_pos == std::string::npos) || (line.find('|', pipe_pos + 1) != std::string::npos))
		{
			std::cerr << RED BOLD << "Error: bad input => " << NEUTRAL << line << std::endl;
			continue ;
		}
		std::string	datePart = line.substr(0, pipe_pos);
		std::string	value = line.substr(pipe_pos + 1);
		size_t		dateStart = datePart.find_first_not_of(" \t");
		size_t		dateEnd = datePart.find_last_not_of(" \t");
		if (dateStart == std::string::npos)
		{
			std::cerr << RED BOLD << "Error: bad input => " << NEUTRAL << line << std::endl;
			continue ;
		}
		std::string	date = datePart.substr(dateStart, dateEnd - dateStart + 1);
		if (date.find(' ') != std::string::npos || date.find('\t') != std::string::npos)
		{
			std::cerr << RED BOLD << "Error: bad input => " << NEUTRAL << line << std::endl;
			continue ;
		}
		size_t		valueStart = value.find_first_not_of(" \t");
		size_t		valueEnd = value.find_last_not_of(" \t");
		if (valueStart == std::string::npos)
		{
			std::cerr << RED BOLD << "Error: bad input => " << line << std::endl;
			continue ;
		}
		std::string	valueStr = value.substr(valueStart, valueEnd - valueStart + 1);
		if (valueStr.find('\t') != std::string::npos && !isValidValue(valueStr))
		{
			std::cerr << RED BOLD << "Error: bad input => " << NEUTRAL << line << std::endl;
			continue ;
		}
		if (!isValidDate(date) || !isValidValue(valueStr))
		{
			if (!isValidDate(date))
				std::cerr << RED BOLD << "Error: bad date format => " << NEUTRAL << date << std::endl;
			else if (!isValidValue(valueStr))
				std::cerr << RED BOLD << "Error: invalid value => " << NEUTRAL << valueStr << std::endl;
			continue ;
		}
		float	floatValue = strToFloat(valueStr);
		if (floatValue > 1000)
		{
			std::cerr << RED BOLD << "Error: Number too large: " << NEUTRAL << floatValue << "." << std::endl;
			continue ;
		}
		float	rate = btc_data.getRate(date);
		float	result = rate * floatValue;
		std::cout << date << " => " << floatValue << " = " << result << std::endl;
	}
	input_file.close();
}

/* --------------------------EXCEPTIONS -------------------------- */
const char *BitcoinExchange::OpenCSVException::what() const throw()
{
	return "Error: could not open database.";
}
