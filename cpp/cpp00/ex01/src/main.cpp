#include "phonebook.hpp"

int main(void)
{
	PhoneBook	newBook;
	std::string	cmd;

	std::cout << "\nWelcome to seojo's PhoneBook\n";
	while (TRUE)
	{
		std::cout << "\nCOMMAND: ADD | SEARCH | EXIT\n";
		std::cout << "> ";
		cmd = get_input();
		if (std::cin.eof())
			break ;
		if (cmd.compare("ADD") == SAME){
			std::cout << "add\n";
			//newBook.add();
		}
		else if (cmd.compare("SEARCH") == SAME){
			std::cout << "search\n";
			//newBook.search();
		}
		else if(cmd.compare("EXIT") == SAME){
			std::cout << "exit\n";
			//break ;
		}
		else{
			std::cout << "else\n";
			//continue ;
		}
	}
//	newBook.exit();
	return (0);
}
