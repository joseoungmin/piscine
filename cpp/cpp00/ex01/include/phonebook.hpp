#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define SAME 0

#include "contact.hpp"

class PhoneBook
{
	private:
		Contact contact[8];
		int		count;
	
	public:
		void	add();
		void	search();
		void	display();

		PhoneBook();
		~PhoneBook();
};

#endif
