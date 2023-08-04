#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <fstream>

enum	e_rate {
	POSSIBLE_NUM,
	INVALID_FLOAT,
	NEGATIVE_NUM,
	LARGE_NUM
};

class BitcoinExchange
{
private:
	std::map<std::string, float> mDatabase;

	void	initDatabase();
	std::string	clearWhiteSpace(std::string str);
	bool	isValidDate(const std::string & date);
	int		isValidExchangeRate(const std::string & exchange_rate);
	void	priceCalculation(const char * filename);
	void	printLine(const std::string & date, double value);

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);

	BitcoinExchange &operator=(const BitcoinExchange &copy);
	
	void	run(const char * filename);
};

#endif