#include "contact.hpp"

static std::string	fixStringWidth(std::string str) {
	if (str.size() > 10)
		str = str.substr(0,9) + ".";
	return (str);
}

void	Contact::showall(){
	std::cout << "  firstName: " << firstName << "\n";
	std::cout << "   lastName: " << lastName << "\n";
	std::cout << "   nickname: " << nickname << "\n";
	std::cout << "phoneNumber: " << phoneNumber << "\n";
}

void	Contact::display(int i){
	std::string str;

	str = i + 1 + '0';
	std::cout << "|" << std::right << std::setw(10) << str;
	str = fixStringWidth(firstName);
	std::cout << "|" << std::right << std::setw(10) << str;
	str = fixStringWidth(lastName);
	std::cout << "|" << std::right << std::setw(10) << str;
	str = fixStringWidth(nickname);	
	std::cout << "|" << std::right << std::setw(10) << str;
	std::cout << "|\n";
}

void	Contact::addContact(std::string info[5]){
	firstName = info[0];
	lastName = info[1];
	nickname = info[2];
	phoneNumber = info[3];
	darkestSecret = info[4];
}