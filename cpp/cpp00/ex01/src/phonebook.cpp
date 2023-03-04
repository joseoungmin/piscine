#include "phonebook.hpp"

PhoneBook::PhoneBook() : count(0) {}

void	PhoneBook::add(){
	const int idx = idx = this->count % 8;

	this->contact[idx].addContact(idx);
	this->count++;
}
