#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};
BitcoinExchange::~BitcoinExchange() {};
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	*this = copy;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy) {
	if (this != &copy)
		mDatabase = copy.mDatabase;
	return (*this);
};

void	BitcoinExchange::initDatabase() {
	std::ifstream	file("data.csv");
	std::string		line;

	if (!file.is_open())
		throw std::runtime_error("Error: data.csv could not be opened");
	if (std::getline(file, line).eof()) {
		file.close();
		throw std::runtime_error("Error: data.csv is empty");
	}
	if (line != "date,exchange_rate") {
		file.close();
		throw std::runtime_error("Error: data.csv is not in the correct format");
	}

	std::string		date;
	std::string		exchange_rate;
	size_t			pos;
	size_t			lineNumber = 1;
	while (std::getline(file, line)) {
		lineNumber++;
		pos = line.find(',');
		if (pos == std::string::npos || line.find(',', pos + 1) != std::string::npos) {
			std::cerr << "Warning: 'data.csv' line " << lineNumber << ": is not in the correct format\n"; continue;}
		date = clearWhiteSpace(line.substr(0, pos));
		exchange_rate = clearWhiteSpace(line.substr(pos + 1));
		if (date.empty()) {
			std::cerr << "Warning: 'data.csv' line " << lineNumber << ": contains an empty date\n"; continue;}
		if (exchange_rate.empty()) {
			std::cerr << "Warning: 'data.csv' line " << lineNumber << ": contains an empty exchange_rate\n"; continue;}
		if (isValidDate(date)) {
			std::cerr << "Warning: 'data.csv' line " << lineNumber << ": contains an invalid date\n"; continue;}
		switch (isValidExchangeRate(exchange_rate)) {
			case INVALID_FLOAT:
				std::cerr << "Warning: 'data.csv' line " << lineNumber << ": contains an invalid exchange_rate\n"; continue;
			case NEGATIVE_NUM:
				std::cerr << "Warning: 'data.csv' line " << lineNumber << ": contains a negative exchange_rate\n"; continue;
		}
		mDatabase[date] = std::strtod(exchange_rate.c_str(), NULL);
	}
}

void	BitcoinExchange::priceCalculation(const char * filename) {
	std::ifstream	file(filename);
	std::string		line;

	if (!file.is_open())
		throw std::runtime_error("Error: " + std::string(filename) + " could not be opened");
	if (std::getline(file, line).eof()) {
		file.close();
		throw std::runtime_error("Error: " + std::string(filename) + " is empty");
	}
	if (line != "date | value") {
		file.close();
		throw std::runtime_error("Error: " + std::string(filename) + " is not in the correct format");
	}

	std::string		date;
	std::string		value;
	size_t			pos;

	while (std::getline(file, line)) {
		pos = line.find('|');
		if (pos == std::string::npos || line.find('|', pos + 1) != std::string::npos) {
			std::cerr << "Error: bad input => [" << line << "\n"; continue;}
		date = clearWhiteSpace(line.substr(0, pos));
		value = clearWhiteSpace(line.substr(pos + 1));
		if (date.empty()) {
			std::cerr << "Error: contains an empty date\n"; continue;}
		if (value.empty()) {
			std::cerr << "Error: contains an empty value\n"; continue;}
		if (isValidDate(date)) {
			std::cerr << "Error: contains an invalid date\n"; continue;}
		switch (isValidExchangeRate(value)) {
			case INVALID_FLOAT:
				std::cerr << "Error: contains an invalid value => [" << value << "]\n"; continue;
			case NEGATIVE_NUM:
				std::cerr << "Error: Not a positive number => [" << value << "]\n"; continue;
			case LARGE_NUM:
				std::cerr << "Error: Too large a number => [" << value << "]\n"; continue;
		}
		printLine(date, std::strtod(value.c_str(), NULL));
	}
}

void	BitcoinExchange::printLine(const std::string & date, double value) {
	std::map<std::string, float>::const_iterator	it;
	float											res = 0;

	std::cout << date;
	it = mDatabase.find(date);
	if (it != mDatabase.end())
		res = value * it->second;
	else
	{
		it = mDatabase.lower_bound(date);
		if (it == mDatabase.begin())
			std::cerr << "(No DB before " << it->first << ")";
		else
			res = value * (--it)->second;
	}
	std::cout << " => " << value << " = " << res << std::endl;
}

std::string	BitcoinExchange::clearWhiteSpace(std::string str) {
	str.erase(0, str.find_first_not_of(" \n\r\t\f\v"));
	str.erase(str.find_last_not_of(" \n\r\t\f\v") + 1);
	return (str);
}

bool	BitcoinExchange::isValidDate(const std::string & date) {
		std::istringstream	dateStream(date);
		char				dash;
		int					year, month, day;

		dateStream >> year >> dash >> month >> dash >> day;
		if (dateStream.fail() || dateStream.get() != EOF) return (true);
		if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) return (true);
		if ((day == 31) && (month == 4 || month == 6 || month == 9 || month == 11)) return (true);
		if (month == 2) {
			bool leapYear = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
			if (day > 29 || (day == 29 && !leapYear)) return (true);
		}
		return (false);
}

int	BitcoinExchange::isValidExchangeRate(const std::string & exchange_rate) {
	char*	endPtr;
	float	value;

	value = std::strtof(exchange_rate.c_str(), &endPtr);
	if (*endPtr && !(*endPtr == 'f' && *(endPtr + 1) == '\0'))
		return (INVALID_FLOAT);
	if (value < 0.f)
		return (NEGATIVE_NUM);
	if (value > 1000.f) 
		return (LARGE_NUM);
	return (POSSIBLE_NUM);
}

void	BitcoinExchange::run(const char * filename) {
	(void)filename;

	try {
		initDatabase();
		priceCalculation(filename);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}
