#include "phonebook.hpp"

std::string get_input(void)
{
	std::string	white_space = " \n\r\t\f\v";
	std::getline(std::cin, cmd);
	str.erase(0, str.find_first_not_of(white_space));
	str.erase(str.find_last_not_of(white_space) + 1);
}

int main(void)
{
	PhoneBook	newBook;
	std::string	cmd;

	while (TRUE)
	{
		std::cout << "\nCOMMAND : ADD | SEARCH | EXIT\n";
		std::cout << "> ";
		cmd = get_input();
		if (std::cin.eof())
			break ;
		delete_white_space(cmd);
		if (cmd.compare("ADD") == SAME)
			newBook.add();
		else if (cmd.compare("SEARCH") == SAME)
			newBook.search();
		else if(cmd.compare("EXIT") == SAME)
			break ;
		else
			continue ;
	}
	newBook.exit();
	return (0);
}
