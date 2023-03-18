#include "Zombie.hpp"

int main(void){
	Zombie	stack = Zombie("stack");
	Zombie*	heap = new Zombie("heap");
	Zombie* made_func = newZombie("made func");

	stack.announce();
	heap->announce();
	made_func->announce();

	delete	heap;
	delete	made_func;
	// system("Leaks BraiiiiiiinnnzzzZ");
	return (0);
}