#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

std::string	getInput(const char *msg);

class	PhoneBook {
	private:
		Contact	contacts[8];
		int		index;

	public:
		void	add(void);
		void	search(void);
		void	displayContact(Contact c);

		PhoneBook(void);
		~PhoneBook(void);
};

#endif
