#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\n";

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "\n";
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "\n";

	delete meta;
	delete j;
	delete i;

	std::cout << "\n";

	const WrongAnimal	*meta2 = new WrongAnimal();
	const WrongAnimal	*i2 = new WrongCat();

	std::cout << std::endl;
	std::cout << meta2->getType() << " " << std::endl;
	std::cout << i2->getType() << " " << std::endl << std::endl;

	meta2->makeSound();
	i2->makeSound(); // Wrongcat : Wrong animal sound

	std::cout << "\n";

	delete meta2;
	delete i2;
	
	std::cout << "\n";
	system("leaks a.out | grep leaked");
	return 0;
}