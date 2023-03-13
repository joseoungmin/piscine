#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "etc.hpp"
# include <iomanip>

class Contact
{
	private:
		std::string	firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		void		showall();
		void		display(int i);
		void		addContact(std::string info[5]);
};

#endif
