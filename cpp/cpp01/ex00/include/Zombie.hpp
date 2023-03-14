#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class	Zombie
{
	private:

	public:
		void	announce( void );
		void	randomChump(std::string name);

		Zombie* newZombie(std::string name);
		Zombie();
		~Zombie();
}

#endif
