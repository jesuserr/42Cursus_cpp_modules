/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:26:53 by jesuserr          #+#    #+#             */
/*   Updated: 2024/01/13 20:42:38 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

BitcoinExchange::BitcoinExchange(void)
{
	//std::cout << "BitcoinExchange constructor called" << '\n';
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& source)
{
	(void)source;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& source)
{
	(void)source;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	//std::cout << "BitcoinExchange destructor called" << '\n';
}

/****************************** MEMBER FUNCTIONS ******************************/

void BitcoinExchange::convert(const std::string filename)
{
	this->_exchangeRates = csvToMap();
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	std::string line;
	while (std::getline(file, line))
		if (!line.empty())
			conversion(line);
	file.close();
}

myMap BitcoinExchange::csvToMap()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	std::string line, key;
	float value = 0;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::getline(ss, key, ',');
		ss >> value;
		_exchangeRates[key] = value;
	}
	file.close();
	return _exchangeRates;
}

void BitcoinExchange::conversion(const std::string line)
{
	std::string str, date;
	std::stringstream ss(line);
	std::getline(ss, str, ' ');
	if (str == "date")
		return;	
 	if (!isValidDate(str) || ss.eof())
	{
		std::cout << "Error: bad input => " << ss.str() << "\n";
		return;
	}
	date = str;
	std::getline(ss, str, '|');
	std::getline(ss, str, ' ');
	float value = 0;
	ss >> value;
	if (!isValidValue(value, ss))
		return;
	std::cout << std::setprecision(5);
	std::cout << date << " => " << value << " = ";
	std::cout << std::setprecision(7);
	std::cout << value * valueAtDate(date) << "\n";
}

bool BitcoinExchange::isValidDate(const std::string date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (year < 2009 || year > 2024 || month < 1 || month > 12)
		return false;
	int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	if (leapYear)
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1])
		return false;
	return true;
}

bool	BitcoinExchange::isValidValue(const float value, const std::stringstream& ss)
{
	if (!ss.eof())
	{
		std::cout << "Error: bad input => " << ss.str() << "\n";
		return false;
	}
	if (value < 0)
	{
		std::cout << "Error: not a positive number.\n";
		return false;
	}
	if (value > 1000)
	{
		std::cout << "Error: too large a number.\n";
		return false;
	}
	return true;
}

float BitcoinExchange::valueAtDate(const std::string date)
{
	myMap::iterator it;

	it = _exchangeRates.find(date);
	if (it == _exchangeRates.end())
	{
		it = _exchangeRates.lower_bound(date);			
		if (it == _exchangeRates.begin())
			return (0);
		it--;
	}
	return (it->second);
}
