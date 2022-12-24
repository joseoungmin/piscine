#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook	pb;
	std::string	str;

	while (str != "EXIT")
	{
		str = getInput("Command > ");
		if (str == "ADD")
			pb.add();
		else if (str == "SEARCH")
			pb.search();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}
