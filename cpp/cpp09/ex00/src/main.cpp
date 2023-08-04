#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: could not open file.\n" 
		<< "Usage: " << av[0] << " <filename>" << std::endl;
		return (1);
	}
	BitcoinExchange exchange;
	exchange.run(av[1]);
	return (0);
}