#include "Zombie.hpp"

void	Zombie::setname(std::string name){
	_name = name;
}

Zombie*	zombieHorde(int N, std::string name) {
	Zombie*				Zombie_arr = new Zombie[N];
	std::stringstream 	ss;
	for (int i = 0; i < N; i++){
		ss.str("");
		ss << (i + 1);
		Zombie_arr[i].setname(name + "[" + ss.str() + "]");
	}
	return (Zombie_arr);
}