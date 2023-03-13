#include "phonebook.hpp"

int main(void)
{
	PhoneBook	newBook;
	std::string	cmd;
	
	while (cmd != "EXIT")
	{
		cmd = get_input("> ");
		if (cmd.compare("ADD") == SAME){
			newBook.add();
		}
		else if (cmd.compare("SEARCH") == SAME){
			newBook.search();
		}
		if (std::cin.eof())
			break ;
	}
	return (0);
}
