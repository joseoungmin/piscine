#include "iter.hpp"

int main(int ac, char** av) {
	iter(av, ac, print);
	std::cout << "\n";

	iter(av, ac, plus_ten);
	iter(av, ac, print);
	std::cout << "\n";

	iter(av, ac, minus_ten);
	iter(av, ac, print);
	std::cout << "\n";

	return (0);
}
