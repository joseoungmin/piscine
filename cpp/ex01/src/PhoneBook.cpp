#include "PhoneBook.hpp"

std::string	eraseWS(std::string str) {
	size_t	find;

	find = str.find_first_not_of(" \n\r\t\f\v");
	str.erase(0, find);
	find = str.find_last_not_of(" \n\r\t\f\v");
	str.erase(find + 1);
	return (str);
}

std::string	getInput(const char *msg) {
	std::string str;

	str = "";
	while (!std::cin.eof() && str == "") {
		std::cout << msg;
		std::getline(std::cin, str);
		str = eraseWS(str);
		if (str != "")
			break ;
	}
	return (str);
}

void	PhoneBook::add(void) {
	if (this->index > 7)
		std::cout << "* Warning: replace info about [ " << \
		this->contacts[this->index % 8].get_firstName() << " ]" << std::endl;
	this->contacts[this->index % 8].set_firstName(getInput("    First Name: "));
	this->contacts[this->index % 8].set_lastName(getInput("     Last Name: "));
	this->contacts[this->index % 8].set_nickname(getInput("      Nickname: "));
	this->contacts[this->index % 8].set_phoneNumber(getInput("  Phone Number: "));
	this->contacts[this->index % 8].set_secret(getInput("Darkest Secret: "));
	if (this->index < 8)
		std::cout << "** Added to PhoneBook index [ " << \
		this->index++ % 8 + 1 << " ] **\n" << std::endl;
	else
		std::cout << "** Updated to PhoneBook index [ " << \
		this->index++ % 8 + 1 << " ] **\n" << std::endl;
}

static std::string	fixStringWidth(std::string str) {
	if (str.size() > 10)
		str = str.substr(0,9) + ".";
	return (str);
}

static int	displayPhoneBook(Contact contacts[8]) {
	std::string	str;
	int			i;

	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "|     Index|First Name| Last name|  Nickname|" << std::endl;
	i = 0;
	while (i < 8 && contacts[i].get_firstName().size()) {
		std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
		str = i + 1 + '0';
		std::cout << "|" << std::right << std::setw(10) << str;
		str = fixStringWidth(contacts[i].get_firstName());
		std::cout << "|" << std::right << std::setw(10) << str;
		str = fixStringWidth(contacts[i].get_lastName());
		std::cout << "|" << std::right << std::setw(10) << str;
		str = fixStringWidth(contacts[i].get_nickname());
		std::cout << "|" << std::right << std::setw(10) << str;
		std::cout << "|" << std::endl;
		i++;
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
	return (i);
}

void	PhoneBook::search(void) {
	std::string	str;

	if (!displayPhoneBook(this->contacts))
	{
		std::cout << "** PhoneBook is empty! **\n" << std::endl;
		return ;
	}
	while (!std::cin.eof())
	{
		str = getInput("Select an index: ");
		if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && \
				this->contacts[str[0] - 1 - '0'].get_firstName().size())
			break ;
		if (str != "")
			std::cout << "* Invalid index!" << std::endl;
	}
	if (!std::cin.eof()) {
		std::cout << std::endl << "<< index [ " << str[0] \
			<< " ] infomation >>" << std::endl;
		this->displayContact(this->contacts[str[0] - 1 - '0']);
	}
}

void	PhoneBook::displayContact(Contact c) {
	std::cout << "    First Name: " << c.get_firstName() << std::endl;
	std::cout << "     Last Name: " << c.get_lastName() << std::endl;
	std::cout << "      Nickname: " << c.get_nickname() << std::endl;
	std::cout << "  Phone Number: " << c.get_phoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << c.get_secret() << std::endl << std::endl;
}

PhoneBook::PhoneBook(void) {
	this->index = 0;
	std::cout << "** Welcome! **\n(Commands : ADD, SEARCH, EXIT)\n" << std::endl;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "\n** Goodbye! **" << std::endl;
}
