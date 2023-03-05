#include "phonebook.hpp"

PhoneBook::PhoneBook() : count(0) {}

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
		std::cout << str[i];
		info[i] = get_input();
		if (std::cin.eof())
			//std::exit();
	}
	contact[idx].addContact(idx);
	count++;
}
