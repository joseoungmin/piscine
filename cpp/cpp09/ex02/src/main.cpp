#include "PmergeMe.hpp"
#include <iostream>

int   main(int argc, char** argv)
{
	if (argc < 2) {
		std::cout << "Invalid number of arguments.\n"
				<< "Usage: ./PmergeMe [Num1] (Num2) (...)\n";
		return 1;
	}
	PmergeMe	pm;
	if (pm.run(argc, argv)) {
		std::cout << "Test run Err!" << std::endl;
		return 1;
	}
	return 0;
}
