#include "phonebook.hpp"

void	PhoneBook::add(){
	const int 			idx = count % 8;
	std::string			info[5];
	const std::string 	str[5] = {
		"    firstName: ",
		"     lastName: ",
		"     nickname: ",
		"  phoneNumber: ",
		"darkestSecret: "
	};
	for (int i = 0; i < 5; i++){
		info[i] = get_input(str[i]);
		if (std::cin.eof() == true){
			std::cout << "\n";
			std::cin.clear();
			clearerr(stdin);
			return ;
		}
		else if (info[i] == "")
			i--;
	}
	if (std::cin.eof() == false)
		contact[idx].addContact(info);
	count++;
}

void	PhoneBook::search(){
	std::string	input;
	int			idx;

	if (count < 1){
		std::cout << "No contacts have been saved\n";
		return ;
	}
	PhoneBook::display();
	while ((input == "" || !("1" <= input && input <= "8")))
	{
		input = get_input("index: ");
		if ("1" <= input && input <= "8"){
			idx = input[0] - '0';
			if (idx > count && idx < 9)
			{
				std::cout << "There are no contacts stored in that index\n";
				input = "";
			}
		}
		else if (std::cin.eof() == true)
			break ;
		else if (input == "")
			;
		else
			std::cout << "Wrong index\n";
	}
	if (std::cin.eof() == true)
	{
		std::cout << "\n";
		std::cin.clear();
		clearerr(stdin);
		return ;
	}
	contact[idx - 1].showall();
}

void	PhoneBook::display(){
	std::cout << "┌──────────┬──────────┬──────────┬──────────┐\n";
	std::cout << "|     Index|First Name| Last name|  Nickname|\n";
	for (int i = 0; i < count && i < 8; i++) {
		std::cout << "├──────────┼──────────┼──────────┼──────────┤\n";
		contact[i].display(i);
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘\n";
}

PhoneBook::PhoneBook() : count(0) {
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	std::cout << "\nWelcome to seojo's PhoneBook\n\n";
	std::cout << "COMMAND: ADD | SEARCH | EXIT\n";
}

PhoneBook::~PhoneBook(){
	std::cout << "\nbye\n";
}
