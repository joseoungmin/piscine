#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define TRUE 1
#define SAME 0

#include "contact.hpp"

class PhoneBook
{
	private:
		Contact contact[8];
		int		count;
	
	public:
		PhoneBook();
		void	add();
		void	search();
		void	searchDisplay(int count);
		void	display(int i);
		void	exit();
};

#endif
