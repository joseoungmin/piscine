#include "Contact.hpp"

std::string	Contact::get_firstName(void) const {
	return (this->firstName);
}

std::string	Contact::get_lastName(void) const {
	return (this->lastName);
}

std::string	Contact::get_nickname(void) const {
	return (this->nickname);
}

std::string	Contact::get_phoneNumber(void) const {
	return (this->phoneNumber);
}

std::string	Contact::get_secret(void) const {
	return (this->secret);
}

void	Contact::set_firstName(std::string str) {
	this->firstName = str;
}

void	Contact::set_lastName(std::string str) {
	this->lastName = str;
}

void	Contact::set_nickname(std::string str) {
	this->nickname = str;
}

void	Contact::set_phoneNumber(std::string str) {
	this->phoneNumber = str;
}

void	Contact::set_secret(std::string str) {
	this->secret = str;
}

Contact::Contact(void) {}
Contact::~Contact(void) {}
