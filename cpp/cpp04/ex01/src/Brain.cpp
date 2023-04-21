#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain default constructor called" << std::endl;
	for (int i=0; i<100; i++)
		ideas[i] = "No ideas";
}

Brain::Brain(const Brain& other){
	*this = other;
}

Brain& Brain::operator=(const Brain& other){
	for (int i=0; i<100; i++)
		ideas[i] = other.ideas[i];
	return (*this);
}

Brain::~Brain(){
	std::cout << "Brain default destructor called" << std::endl;
}
